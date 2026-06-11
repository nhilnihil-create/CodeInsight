#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int n, i;
    double x[100], y[100], d, di;

    cin >> n;
    for (i = 0; i < n; i++) cin >> x[i];
    for (i = 0; i < n; i++) cin >> y[i];

    for (i = 0, d = 0; i < n; i++) {
        d += abs(x[i] - y[i]);
    }
    printf("%.6lf\n", d);

    for (i = 0, d = 0; i < n; i++) {
        d += (x[i] - y[i]) * (x[i] - y[i]);
    }
    printf("%.6lf\n", sqrt(d));

    for (i = 0, d = 0; i < n; i++) {
        d += abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
    }
    printf("%.6lf\n", pow(d, 1.0/3.0));

    // Chebyshev distance
    for (i = 0, d = 0; i < n; i++) {
        di = abs(x[i] - y[i]);
        if (d < di) d = di;
    }
    printf("%.6lf\n", d);

    return 0;
}