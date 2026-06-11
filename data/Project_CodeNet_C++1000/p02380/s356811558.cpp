#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;
using ull = unsigned long long;

constexpr double Pi = 3.141592653;

int main()
{
    double a, b, cAngle;
    cin >> a >> b >> cAngle;

    cAngle = cAngle * 2 * Pi / 360.0;

    double S = a * b * sin(cAngle) / 2;
    double L = a + b + sqrt(a*a + b*b - 2 * a * b * cos(cAngle));
    double h = b*sin(cAngle);

    cout << fixed;
    cout << setprecision(8) << S << " " << L << " " << h << endl;


    return 0;
}