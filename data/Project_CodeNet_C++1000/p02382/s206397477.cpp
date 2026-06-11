#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    double x[100], y[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    double d1 = 0.0, d2 = 0.0, d3 = 0.0, dm = 0.0;
    for (int i = 0; i < n; ++i) {
        d1 += abs(x[i] - y[i]);
        d2 += pow(x[i] - y[i], 2.0);
        d3 += abs(pow(x[i] - y[i], 3.0));
        dm = (dm < abs(x[i] - y[i]))? abs(x[i] - y[i]) : dm;
    }

    cout << fixed << setprecision(10);
    cout << pow(d1, 1.0 / 1.0) << endl;
    cout << pow(d2, 1.0 / 2.0) << endl;
    cout << pow(d3, 1.0 / 3.0) << endl;
    cout << dm << endl;
}





