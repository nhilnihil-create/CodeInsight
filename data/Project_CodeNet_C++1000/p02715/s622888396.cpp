#include <iostream>

using namespace std;
using ll = long long;

const int K = 1e5 + 10;
const int mod = 1e9 + 7;

ll dp[K];

ll qmi(int m, int k, int p) {
    ll res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = k; i >= 1; --i) {
        dp[i] = qmi(k / i, n, mod);
        for (int j = 2 * i; j <= k; j += i) {
            dp[i] -= dp[j];
            dp[i] = (dp[i] % mod + mod) % mod;
        }
    }

    ll res = 0;
    for (int i = 1; i <= k; i++) (res += dp[i] * i % mod) %= mod;
    cout << res << '\n';

    return 0;
}
