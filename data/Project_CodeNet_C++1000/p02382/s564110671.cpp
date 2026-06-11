#include <cstdio>
#include <cmath>

int main() {
    int n, x[100], y[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    double d1, d2, d3, d4;
    d1 = d2 = d3 = d4 = 0.0;
    for (int i = 0; i < n; i++) {
        d1 += fabs(x[i]-y[i]);
        d2 += pow(fabs(x[i]-y[i]), 2);
        d3 += pow(fabs(x[i]-y[i]), 3);
        if (d4 < fabs(x[i]-y[i])) {
            d4 = fabs(x[i]-y[i]);
        }
    }
    d2 = sqrt(d2);
    d3 = pow(d3, 1.0/3.0);
    printf("%f\n%f\n%f\n%f\n", d1, d2, d3, d4);
    return 0;
}
