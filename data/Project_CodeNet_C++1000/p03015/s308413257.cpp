#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
    string l;
    cin >> l;
    int n = l.size();
    ll dp[2][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 2;
    for (int i = 1; i < n; i++) {
        if (l[i] == '1') {
            dp[0][i] = (dp[0][i - 1] * 3 + dp[1][i - 1]) % MOD;
            dp[1][i] = dp[1][i - 1] * 2 % MOD;
        } else {
            dp[0][i] = dp[0][i - 1] * 3 % MOD;
            dp[1][i] = dp[1][i - 1];
        }
    }
    cout << (dp[0][n - 1] + dp[1][n - 1]) % MOD << endl;
    return 0;
}
