#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    // input
    int a, b, C;
    cin >> a >> b >> C;

    // solve
    // caution! cos, sin takes radian
    double rad;
    double PI = acos(-1);
    rad = (C * PI) / 180;

    long double S, L, h;
    S = ( a * b * sin(rad) ) / 2;
    L = a + b + sqrt( pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad) );
    h = b * sin(rad);

    // output
    cout << fixed;
    cout << setprecision(6) << S << endl
         << setprecision(6) << L << endl
         << setprecision(6) << h << endl;
}
