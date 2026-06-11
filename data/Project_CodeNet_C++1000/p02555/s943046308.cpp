#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

constexpr int NMAX = 2010;

ll _binom[NMAX][NMAX];

ll binom(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return _binom[n][r];
}

int main() {
    for (int i = 0; i < NMAX; ++i) {
        _binom[i][0] = _binom[i][i] = 1;
        for (int j = 1; j < i; ++j) _binom[i][j] = (_binom[i-1][j] + _binom[i-1][j-1]) % MOD;
    }
    int s; scanf("%d", &s);
    ll ans = 0;
    for (int len = 1; len <= s; ++len) {
        int as = s - 2 * len;
        ans = (ans + binom(as - 1, len - 1)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
