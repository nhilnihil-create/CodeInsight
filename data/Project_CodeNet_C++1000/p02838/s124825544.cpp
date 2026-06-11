#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    const ll MOD = 1e9 + 7;
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(bit, 61) {
        int one = 0, zero = 0;
        rep(i, n) {
            if (a[i] >> bit & 1)
                one++;
            else
                zero++;
        }

        ll p = (1ll << bit) % MOD;
        ans += p * one % MOD * zero;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
