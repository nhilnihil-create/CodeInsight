#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double y = (2 * (x / a)) / b;
    if (y < a)
        cout << fixed << setprecision(10)
             << atan(b / y) * 180 / (atan(1.0) * 4) << endl;
    else {
        y = (2 * (x / a)) / a - b;
        cout << fixed << setprecision(10)
             << atan((b - y) / a) * 180 / (atan(1.0) * 4)
             << endl;
    }
    return 0;
}