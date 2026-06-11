#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int i, j, num, start, end, c;
    double a, b, rad, s, l, h;

    cin >> a >> b >> c;

    rad = M_PI /180.0 * c;

    cout << fixed <<setprecision(10) << 0.5*a*b*sin(rad) << endl;
    cout << fixed <<setprecision(10) << sqrt(b*b+a*a-2.0*a*b*cos(rad))+a+b << endl;
    cout << fixed <<setprecision(10) << b*sin(rad) << endl;

    return 0;
}

