#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {
    double a, b, c, C, S, L, h;

    cin >> a >> b >> C;
    h = b * sin(C * M_PI / 180.0);
    S = 0.5 * a * h;
    c = sqrt(a * a + b * b - 2 * a * b * cos(C * M_PI / 180.0));
    L = a + b + c;

    cout << fixed;
    cout.precision(4);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;

    return 0;
}