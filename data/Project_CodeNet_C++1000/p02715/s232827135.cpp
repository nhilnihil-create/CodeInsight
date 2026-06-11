#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int dp[N];

int fp(int a, int p) {
    if (!p) return 1;
    int t = fp(a, p >> 1);
    t = (t * 1LL * t) % mod;
    if (p & 1) t = (t * 1LL * a) % mod;
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k; i >= 1; i--) {
        dp[i] = fp(k / i, n);
        for (int j = i + i; j <= k; j += i) dp[i] = (dp[i] - dp[j] + mod) % mod;
        ans = (ans + (dp[i] * 1LL * i) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}