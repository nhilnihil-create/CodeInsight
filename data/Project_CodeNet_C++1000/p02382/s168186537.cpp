#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {

    int n;
    cin >> n;

    int *xs = new int[n];
    int *ys = new int[n];
    double rs = 0.0;

    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> ys[i];
    }

    for (int i = 0; i < n; ++i) {
        rs += fabs(xs[i] - ys[i]);
    }
    cout << fixed << setprecision(7) << rs << endl;

    rs = 0.0;
    for (int i = 0; i < n; ++i) {
        rs += pow(xs[i] - ys[i], 2);
    }
    cout << fixed << setprecision(7) << sqrt(rs) << endl;

    rs = 0.0;
    for (int i = 0; i < n; ++i) {
        rs += pow(fabs(xs[i] - ys[i]), 3);
    }
    cout << fixed << setprecision(7) << cbrt(rs) << endl;

    rs = 0.0;
    for (int i = 0; i < n; ++i) {
        if (rs < fabs(xs[i] - ys[i])) {
            rs = fabs(xs[i] - ys[i]);
        }
    }
    cout << fixed << setprecision(7) << rs << endl;

    delete[] xs;
    delete[] ys;

    return 0;
}