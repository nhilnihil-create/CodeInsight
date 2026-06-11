// 5/4
// 過去問ガリガリ

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// int mod = 1000000007;

// const ll MAX = 1000000010;
const ll MOD = 1000000007;

// long long fac[MAX], finv[MAX], inv[MAX];

// x^nのmodを返す
ll f(ll x, ll n) {
    if (n == 0) return 1;
    
    ll r = f(x, n / 2);
    r *= r;
    r %= MOD;

    if (n % 2 == 1) r *= x;

    return r % MOD;
}

ll comb(ll n, ll a) {
    ll X = 1, Y = 1;  // Xが分母、Yが分子
    
    for(ll i = 0; i < a; i++) {
        Y *= n - i;
        X *= i + 1;

        Y %= MOD;
        X %= MOD;
    }

    return (Y * f(X, MOD - 2)) % MOD;
}


int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    // int mod2_10000 = 1;
    // rep(i, 10000) {
    //     mod2_10000 *= 2;
    //     mod2_10000 %= 1000000007;
    // }

    // COMinit();

    // int ans_a = 1, ans_b = 1;
    // rep(i, a) {
    //     ans_a = (ans_a * (a - i) / (i + 1)) % mod;
    // }
    // rep(i, b) {
    //     ans_b = (ans_b * (b - i) / (i + 1)) % mod;
    // }

    // cout << mod2_10000 << endl;

    // cout << modpow(2, n, MOD) - 1 - COM(n, a) - COM(n, b) << endl;

    ll ans = f(2, n) - 1;
    // cout << f(5) << endl;

    // ll X = 1, Y = 1;
    // rep(i, a) {
    //     Y *= n - i;
    //     X *= i + 1;

    //     Y %= MOD;
    //     X %= MOD;
    // }
    // cout << X << " " << Y << endl;

    // cout << ans << endl;

    ans -= comb(n, a);
    ans = (ans + MOD) % MOD;
    // cout << ans << endl;
    ans -= comb(n, b);
    ans = (ans + MOD) % MOD;

    cout << ans << endl;
}
