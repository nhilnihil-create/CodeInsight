#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity" << endl;
        return 0;
    }
    ll max1, max2, min1, min2;
    if (t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2) {
        max1 = b1;
        max2 = b2;
        min1 = a1;
        min2 = a2;
    } else {
        max1 = a1;
        max2 = a2;
        min1 = b1;
        min2 = b2;
    }
    if (min1 == max1) {
        cout << "infinity" << endl;
        return 0;
    }
    if (min1 < max1) {
        cout << 0 << endl;
        return 0;
    }

    // ll max_diff = (min1 - max1) * t1;
    // ll phase_diff = (max1 - min1) * t1 + (max2 - min2) * t2;
    // ll ans = (max_diff + phase_diff - 1) / phase_diff;

    ll max_diff = (min1 - max1) * t1;
    ll phase_diff = (max1 - min1) * t1 + (max2 - min2) * t2;
    ll ans = max_diff / phase_diff;

    ans *= 2;
    ans++;
    if (max_diff % phase_diff == 0) ans--;
    cout << ans << endl;
}