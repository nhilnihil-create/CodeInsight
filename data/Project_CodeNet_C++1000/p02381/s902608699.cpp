#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    double* s;
    while (cin >> n && n > 0) {
        s = new double[n];
        double t = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            t += s[i];
        }
        double m = t / n;
        double u = 0;
        for (int i = 0; i < n; i++) {
            u += (s[i] - m) * (s[i] - m);
        }
        cout << fixed << setprecision(8) << sqrt(u/n) << "\n";
        delete s;
    }
}