#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main () {
    int n;
    cin >> n;
    double X[100], Y[100];
    for (int i=0; i<n; i++) cin >> X[i];
    for (int i=0; i<n; i++) cin >> Y[i];

    double manhattan = 0;
    for (int i=0; i<n; i++) manhattan += fabs(X[i] - Y[i]);
    printf("%lf\n", manhattan);

    double s = 0;
    for (int i=0; i<n; i++) s += pow(X[i] - Y[i], 2);
    double euclid = sqrt(s);
    printf("%lf\n", euclid);

    double c = 0;
    for (int i=0; i<n; i++) c += pow(fabs(X[i] - Y[i]), 3);
    double cublic = cbrt(c);
    printf("%lf\n", cublic);

    double max = -1;
    for (int i=0; i<n; i++) {
        double tmp = fabs(X[i] - Y[i]);
        if (max < tmp) max = tmp;
    }
    printf("%lf\n", max);
}