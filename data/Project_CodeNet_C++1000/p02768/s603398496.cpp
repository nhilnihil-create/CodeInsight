#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
ll modinv(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;
    ll res = 0;
    ll MOD = 1000000007;
    res = modpow(2, n, MOD) - 1;
    res = mod(res,MOD);
    if (a > b) swap(a,b);
    // nCa
    ll X = 1;
    for (ll i = n; i >= n - a + 1; i--) {
        X *= i;
        X %= MOD;
    }
    ll Y = 1;
    rep(i,a) Y *= (i+1), Y %= MOD;
    Y = modpow(Y, MOD - 2, MOD);
    ll Z = X * Y % MOD;
    res -= Z;
    res = mod(res, MOD);

    // nCb 
    // Reuse X. Since b is always bigger than a, you can continue from X
    for (ll i = n - a; i >= n - b + 1; i--) {
        X *= i;
        X %= MOD;
    }
    Y = 1;
    rep(i,b) Y = Y * (i+1) % MOD;
    Y = modpow(Y, MOD - 2, MOD);
    Z = X * Y % MOD;
    res -= Z;
    res = mod(res, MOD);

    cout << res << endl;
}
