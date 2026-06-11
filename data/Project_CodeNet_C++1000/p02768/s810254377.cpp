#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long int;

const int MOD_NUM = 1e9 + 7;

// 二分累乗法
ll pow_mod(ll n, ll p, ll m) {
    const int N = 64;

    vector<ll> memory(N);
    memory[0] = n % m;
    rep(i, N) memory[i + 1] = memory[i] * memory[i] % m;

    ll ans = 1;
    rep(i, N) {
        ll k = p >> i;
        if (k == 0)
            break;
        else if (k & 1)
            ans = (ans * memory[i]) % m;
    }

    return ans;
}

ll comb(ll n, ll a, ll m) {
    ll X = 1;
    ll Y = 1;
    for (int i = 1; i <= a; i++) {
        X = X * (n + 1 - i) % m;
        Y = Y * i % m;
    }

    ll inv_Y = pow_mod(Y, m - 2, m);
    return X * inv_Y % m;
}

int main() {
    // Input
    int n, a, b;
    cin >> n >> a >> b;

    // Process
    ll all = pow_mod(2, n, MOD_NUM) - 1;

    ll comb_a = comb(n, a, MOD_NUM);
    ll comb_b = comb(n, b, MOD_NUM);
    ll ans = (all + MOD_NUM * 2 - comb_a - comb_b) % MOD_NUM;

    // Output
    cout << ans << endl;

    return 0;
}
