#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    int x[1002], y[1002];
    double r1, r2, r3, rf, sum, tmp;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
    }

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(abs(x[i] - y[i]), 1);
    }
    r1 = pow(sum, 1.0 / 1);

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(abs(x[i] - y[i]), 2);
    }
    r2 = pow(sum, 1.0 / 2);

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(abs(x[i] - y[i]), 3);
    }
    r3 = pow(sum, 1.0 / 3);

    sum = 0;
    rf = -1;
    for (int i = 0; i < n; ++i) {
        if (rf < (tmp = abs(x[i] - y[i]))) {
            rf = tmp;
        }
    }

    printf("%.6lf\n%.6lf\n%.6lf\n%.6lf\n", r1,r2,r3,rf);
}