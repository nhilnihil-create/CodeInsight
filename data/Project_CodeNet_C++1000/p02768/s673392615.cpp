#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int power(ll n, ll p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        ll t = power(n, p / 2);
        return t * t % MOD;
    }
    return n * power(n, p - 1) % MOD;
}

int nCr(int n, int r) {
    ll x = 1, y = 1;
    rep(i, r) {
        x = x * (n - i) % MOD;
        y = y * (i + 1) % MOD;
    }
    return x * power(y, MOD - 2) % MOD;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = power(2, n) - 1 - nCr(n, a) - nCr(n, b);

    cout << (ans % MOD + MOD) % MOD << endl;
    return 0;
}
