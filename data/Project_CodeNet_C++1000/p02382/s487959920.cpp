#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int vx[n];
    int vy[n];
    double sum1 = 0, sum2 = 0, sum3 = 0, chebyshev = 0;
    double d1, d2, d3;
    for (int i = 0; i < n; i++) {
        cin >> vx[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vy[i];
    }
    for (int i = 0; i < n; i++) {
        sum1 += pow( abs(vx[i] - vy[i]), 1.0);
        sum2 += pow( abs(vx[i] - vy[i]), 2.0);
        sum3 += pow( abs(vx[i] - vy[i]), 3.0);
        if (chebyshev < abs(vx[i]-vy[i])) chebyshev = abs(vx[i]-vy[i]);
    }

    d1 = pow(sum1, 1/1.0);
    d2 = pow(sum2, 1/2.0);
    d3 = pow(sum3, 1/3.0);

    printf("%.6f\n%.6f\n%.6f\n%.6f\n", d1, d2, d3, chebyshev);

    return 0;
}