#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    int X[n], Y[n];
    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> Y[i];
    
    double a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) a += abs(X[i] - Y[i]);
    for (int i = 0; i < n; i++) b += abs(X[i] - Y[i]) * abs(X[i] - Y[i]);
    b = sqrt(b);
    for (int i = 0; i < n; i++) c += abs(X[i] - Y[i]) * abs(X[i] - Y[i]) * abs(X[i] - Y[i]);
    c = cbrt(c);
    for (int i = 0; i < n; i++) {
        double tmp = abs(X[i] - Y[i]);
        d = max (d, tmp);
    }

    printf("%.6lf\n", a);
    printf("%.6lf\n", b);
    printf("%.6lf\n", c);
    printf("%.6lf\n", d);
    return 0;
}
