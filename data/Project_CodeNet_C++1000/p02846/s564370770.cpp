#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int t1, t2;
    ll a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll d1 = t1 * (a1 - b1);
    ll d2 = d1 + t2 * (a2 - b2);
    if ((d1 > 0 && d2 > 0) || (d1 < 0 && d2 < 0)) {
        cout << 0 << endl;
    } else if (d1 == 0 || d2 == 0) {
        cout << "infinity" << endl;
    } else {
        ll count = abs(d1) / abs(d2) + 1;
        if (abs(d1) % abs(d2)) {
            cout << 2 * count - 1 << endl;
        } else {
            cout << 2 * count - 2 << endl;
        }
    }
    return 0;
}
