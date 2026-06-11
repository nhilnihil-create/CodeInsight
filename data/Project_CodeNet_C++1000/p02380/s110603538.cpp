#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int a, b, C;
    cin >> a >> b >> C;
    double c = 3.14159265 * C / 180.0f ;
    double S = 0.5f * a * b * sin(c);
    double l = a + b + sqrt(a*a + b*b - 2.0f * a * b * cos(c));
    double h = b * sin(c);
    cout << fixed;
    cout << setprecision(6) << S << endl;
    cout << setprecision(6) << l << endl;
    cout << setprecision(6) << h << endl;
    return 0;
}
