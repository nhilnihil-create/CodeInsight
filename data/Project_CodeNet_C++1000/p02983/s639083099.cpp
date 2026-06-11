#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll l, r;
    cin >> l >> r;

    if (r - l + 1 >= 2019) {
        cout << 0 << endl;
    } else {
        ll ans = 1e10;
        for (ll i = l; i <= min(r, l+2019+1); i++) {
            for (ll j = i + 1; j <= min(r, l+2019+1); j++) {
                ans = min(ans, (i * j) % 2019);
            }
        }
        cout << ans << endl;
    }
}