#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007
int main() {
    int n, m; cin >> n >> m;
    vector<int> dp(n+1);
    vector<bool> is_safe(n+1, true);
    rep(i, m) {
        int tmp;
        cin >> tmp;
        is_safe[tmp] = false;
    }
    dp[0] = 1;
    if (is_safe[1]) dp[1] = 1;
    //if (is_safe[2]) dp[2] = 2;
    int j = 0;
    for (int i = 2; i < n+1; i++) {
        if (is_safe[i-2])
            dp[i] += dp[i-2];
        if (is_safe[i-1])
            dp[i] += dp[i-1];
        dp[i] = dp[i] % MOD;
    }
    cout << dp[n]% MOD  << endl;
}
