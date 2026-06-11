#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll i, ll mod){
    return modpow(i, mod-2, mod);
}

ll comb(ll n, ll a, ll mod) {
    ll ans = 1, denom = 1;
    for (int i = 0; i < a; i++) {
        ans = ans * (n - i) % mod;
        denom = denom * (i+1) % mod;
    }
    ans = ans * modinv(denom, mod) % mod;
    return ans;
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    ll ans = (modpow(2, n, MOD) - 1) % MOD;
    ans = (ans - comb(n, a, MOD)) % MOD;
    ans = (ans - comb(n, b, MOD)) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}
