#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, x[100], y[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    // p = 1
    int d1 = 0;
    for (int i = 0; i < n; i++) {
        d1 += abs(x[i] - y[i]);
    }
    printf("%d\n", d1);

    // p = 2
    double d2 = 0;
    for (int i = 0; i < n; i++) {
        d2 += (x[i] - y[i]) * (x[i] - y[i]);
    }
    d2 = sqrt(d2);
    printf("%.6f\n", d2);

    // p = 3
    double d3 = 0;
    for (int i = 0; i < n; i++) {
        d3 += abs((x[i] - y[i])) * (x[i] - y[i]) * (x[i] - y[i]);
    }
    d3 = pow(d3, 1.0/3.0);
    printf("%.6f\n", d3);

    // p = INF
    int di = 0;
    for (int i = 0; i < n; i++) {
        di = max(di, (int)abs(x[i] - y[i]));
    }
    printf("%d\n", di);

    return 0;
}