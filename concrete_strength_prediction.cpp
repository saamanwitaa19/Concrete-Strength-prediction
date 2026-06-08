#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ConcreteStrength
{
private:
    double cement;
    double water;
    double aggregate;
    double age;
    double strength;
    double wcRatio;
public:
    ConcreteStrength(double c, double w, double a, double ag)
    {
        cement = c;
        water = w;
        aggregate = a;
        age = ag;
        strength = 0;
        wcRatio = 0;
    }
    void calculateWCRatio()
    {
        wcRatio = water / cement;
    }
    void predictStrength()
    {
        calculateWCRatio();
        strength = (0.12 * cement)-(0.08 * water)+ (0.015 * aggregate)+ (0.6 * age)- (15 * wcRatio);
        if (strength < 0)
            strength = 0;
    }
    string classifyGrade()
    {
        if (strength >= 60)
            return "High Strength Concrete";
        else if (strength >= 40)
            return "Medium Strength Concrete";
        else if (strength >= 20)
            return "Normal Strength Concrete";
        else
            return "Low Strength Concrete";
    }
    void displayReport()
    {
        cout << "\n=====================================\n";
        cout << "      CONCRETE STRENGTH REPORT\n";
        cout << "=====================================\n";
        cout << fixed << setprecision(2);
        cout << "Cement Quantity      : " << cement << " kg/m^3\n";
        cout << "Water Quantity       : " << water << " kg/m^3\n";
        cout << "Aggregate Quantity   : " << aggregate << " kg/m^3\n";
        cout << "Concrete Age         : " << age << " days\n";
        cout << "Water-Cement Ratio   : " << wcRatio << endl;
        cout << "Predicted Strength   : " << strength << " MPa\n";
        cout << "Concrete Category    : " << classifyGrade() << endl;
        cout << "=====================================\n";
    }
};
int main()
{
    int n;
    cout << "=====================================\n";
    cout << " CONCRETE STRENGTH PREDICTION SYSTEM\n";
    cout << "=====================================\n";
    cout << "\nEnter Number of Concrete Samples: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        double cement, water, aggregate, age;
        cout << "\nSample " << i << endl;
        do
        {
            cout << "Enter Cement Quantity (kg/m^3): ";
            cin >> cement;
        } while(cement <= 0);
        do
        {
            cout << "Enter Water Quantity (kg/m^3): ";
            cin >> water;
        } while(water <= 0);
        do
        {
            cout << "Enter Aggregate Quantity (kg/m^3): ";
            cin >> aggregate;
        } while(aggregate <= 0);
        do
        {
            cout << "Enter Age of Concrete (days): ";
            cin >> age;
        } while(age <= 0);
        ConcreteStrength sample(cement, water, aggregate, age);
        sample.predictStrength();
        sample.displayReport();
    }
    cout << "\nThank You for Using the System.\n";
    return 0;
}