#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int power(ll a, ll b) {
    int c = 1;
    while (b) {
        if (b & 1) c = c * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return c;
}

int nCr(int a, int b) {
    ll x = 1, y = 1;
    rep(i, b) {
        x = x * (a - i) % MOD;
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
