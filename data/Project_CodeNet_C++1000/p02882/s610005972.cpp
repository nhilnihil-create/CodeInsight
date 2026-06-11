
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double a, b, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10) << fixed;

    double pi = atan(1) * 4;
    cin >> a >> b >> x;
    x /= a;
    if (x <= a * b / 2) {
        double d = atan2(b, x * 2 / b) * 180 / pi;
        cout << d << endl;
    } else {
        double k = (a * b - x) * 2 / a;
        double d = atan2(k, a) * 180 / pi;
        cout << d << endl;
    }

    return 0;
}

