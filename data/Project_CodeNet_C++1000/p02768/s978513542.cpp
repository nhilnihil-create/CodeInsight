#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

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

int main() {
    ll n, a, b;
    ll X, Y;
    cin >> n >> a >> b;

    ll ans = mod_pow(2, n, MOD);
    ans--;

    ll x = 1;
    ll y = 1;

    for (int i = n; i >= n-a+1; i--) {
        x = x*i%MOD;
        y = y*(n-i+1)%MOD;
    }
    X = x * mod_pow(y, MOD-2, MOD) % MOD;

    x = 1;
    y = 1;
    for (int i = n; i >= n-b+1; i--) {
        x = x*i%MOD;
        y = y*(n-i+1)%MOD;
    }

    Y = x * mod_pow(y, MOD-2, MOD) % MOD;

    ans -= X;
    if (ans < 0) ans += MOD;
    ans -= Y;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}
