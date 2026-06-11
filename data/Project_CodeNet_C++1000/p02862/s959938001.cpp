#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x, ll mod) { return mod_pow(x, mod - 2, mod); }

ll mod_comb(int n, int r, ll mod) {
    if (n < r) return 0;
    if (n - r < r) r = n - r;
    ll x = 1, y = 1;
    for (int i = 0; i < r; i++) x = x * (n - i) % mod;
    for (int i = r; i > 0; i--) y = y * i % mod;
    return x * mod_inv(y, mod) % mod;
}

int main() {
    ll x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll a = 0, b = 0;
    for (ll i = 0; i <= x; i++) {
        ll ta = x - i;
        ll tb = y - i * 2;
        if (ta < 0 || tb < 0) continue;
        if (tb * 2 == ta) {
            a = i, b = tb;
            break;
        }
    }
    ll ans = mod_comb(a + b, b, MOD);
    if (a == 0 && b == 0) ans = 0;
    cout << ans << endl;
}