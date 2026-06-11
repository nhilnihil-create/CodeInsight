#include<iostream>
using namespace std;
#include<iomanip>

#define _USE_MATH_DEFINES
#include<cmath>

int main()
{
    double a, b, t;
    int C;
    cin >> a >> b >> C;
    t = (M_PI * C * 1.0) / 180;

    cout << fixed << setprecision(10) << endl;
    cout << 0.5 * a * b * sin(t) << endl;
    cout << a + b + sqrt(a * a + b * b - 2 * a * b * cos(t)) << endl;
    cout << b * sin(t) << endl;

    return 0;
}