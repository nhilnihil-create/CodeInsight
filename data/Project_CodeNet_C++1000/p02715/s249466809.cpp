#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

ll qpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll dp[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll res = 0;
    for (int i = k; i; i--) {
        dp[i] = qpow(k / i, n);
        for (int j = i + i; j <= k; j += i) dp[i] -= dp[j];
        res = (res + i * dp[i] % MOD) % MOD;
    }
    printf("%lld\n", (res + MOD) % MOD);
    return 0;
}
