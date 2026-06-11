#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
ll dp[100005][2];

int main() {
    string L;
    cin >> L;
    int n = L.size();
    dp[0][0] = 1;
    rep(i, n) {
        if (L[i] == '1') {
            dp[i+1][0] = dp[i][0] * 2 % MOD;
            dp[i+1][1] = (dp[i][1] * 3 + dp[i][0]) % MOD;
        } else {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1] * 3 % MOD;
        }
    }
    ll ans = dp[n][0] + dp[n][1];
    ans %= MOD;
    cout << ans << endl;
    return 0;
}