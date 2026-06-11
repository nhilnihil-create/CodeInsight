#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const double rad = 180 / M_PI;

int main() {
    cout<< fixed << setprecision(10);
    double a, b, x;
    cin >> a >> b >> x;
    if (x <= a * a * b / 2) {
        double p = x * 2 / a / b;
        cout << atan(b / p) * rad << endl;
    } else {
        double p = (a * b - x / a) * 2 / a;
        cout << 90 - atan(a / p) * rad << endl;
    }
}
