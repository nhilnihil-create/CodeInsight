#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int* x; int* y;
    x = new int[n]; y = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    double d;
    for (int i = 0; i < n; i++) {
        double e = x[i]-y[i];
        if (e < 0) e = e*(-1);
        d += e;
    }
    cout << fixed << setprecision(6) << d << "\n";
    d = 0;
    for (int i = 0; i < n; i++) {
        d += (x[i]-y[i])*(x[i]-y[i]);
    }
    cout << sqrt(d) << "\n";
    d = 0;
    for (int i = 0; i < n; i++) {
        double e = x[i]-y[i];
        if (e < 0) e = e*(-1);
        d += e * e * e;
    }
    cout << cbrt(d) << "\n";
    d = 0;
    for (int i = 0; i < n; i++) {
        double e = x[i]-y[i];
        if (e < 0) e = e *(-1);
        if (d < e) d = e;
    }
    cout << d << "\n";
}