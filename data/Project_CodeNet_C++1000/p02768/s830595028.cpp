#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;
ll mod_pow(ll x, ll y) {
    if (y == 0)return 1;
    else {
        return mod_pow(x * x % MOD, y >> 1) * (y & 1 ? x : 1) % MOD;
    }
}
ll nck(ll n, ll k) {
    k = min(k, n - k);
    ll x = 1, y = 1;
    for (ll i = 0; i < k; i++) {
        x = x * (n - i) % MOD;
        y = y * (i + 1) % MOD;
    }
    return x * mod_pow(y, MOD - 2) % MOD;
}
int main() {
    ll n, a, b; 
    cin >> n >> a >> b;
    ll ans = mod_pow(2, n) - 1 - nck(n, a) - nck(n, b);
    ans += MOD*4;
    ans %= MOD;
    cout << ans << endl;
}
