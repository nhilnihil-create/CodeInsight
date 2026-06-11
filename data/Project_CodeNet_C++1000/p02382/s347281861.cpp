#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, x[100], y[100];
    double d1 = 0.0, d2 = 0.0, d3 = 0.0, d4 = 0.0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    for (int i = 0; i < n; i++) {
        d1 += abs(x[i] - y[i]);
        d2 += pow(abs(x[i] - y[i]), 2.0);
        d3 += pow(abs(x[i] - y[i]), 3.0);
        if (abs(x[i] - y[i]) > d4) {
            d4 = abs(x[i] - y[i]);
        }
    }
    d2 = pow(d2, 1.0 / 2.0);
    d3 = pow(d3, 1.0 / 3.0);

    cout << fixed << setprecision(6) << d1 << endl;
    cout << fixed << setprecision(6) << d2 << endl;
    cout << fixed << setprecision(6) << d3 << endl;
    cout << fixed << setprecision(6) << d4 << endl;

    return 0;
}