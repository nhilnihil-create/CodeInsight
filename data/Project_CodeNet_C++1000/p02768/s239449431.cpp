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

ll mod_com(int n, int k, ll mod) {
    if (n < k) return 0;
    if (n - k < k) k = n - k;
    ll x = 1, y = 1;
    for (int i = 0; i < k; i++) x = x * (n - i) % mod;
    for (int i = k; i > 0; i--) y = y * i % mod;
    return x * mod_inv(y, mod) % mod;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = (mod_pow(2, n, MOD) - 1) - mod_com(n, a, MOD) - mod_com(n, b, MOD);
    while (ans < 0) ans += MOD;
    cout << ans << endl;
}