#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 998244353;
ll fpow(ll a, ll b, ll m = MOD) {
    ll ans = 1;
    b %= (m - 1); // fermat's little theorem
    a %= m;
    while (b) {
        if (b & 1) {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}
ll dp[3014][3014];
int a[3014];
const ll inv2 = fpow(2, MOD - 2);
int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = fpow(2, n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i+1][j] += dp[i][j]; dp[i+1][j] %= MOD;
            if (j + a[i] > s) continue;
            dp[i+1][j+a[i]] += dp[i][j] * inv2; dp[i+1][j+a[i]] %= MOD;
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}