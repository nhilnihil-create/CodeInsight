#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MOD 1000000007

ll dp[10000000][4];

int main() {
    ll n;
    cin >> n;
    dp[0][0] = 1;
    rep(i, n) {
        dp[i + 1][0] = dp[i][0] * 8;
        dp[i + 1][1] = dp[i][0] + dp[i][1] * 9;
        dp[i + 1][2] = dp[i][0] + dp[i][2] * 9;
        dp[i + 1][3] = dp[i][1] + dp[i][2] + dp[i][3] * 10;
        rep(j, 4) {
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[n][3] << endl;
    return 0;
}
