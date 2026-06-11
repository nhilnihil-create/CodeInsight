#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin >> S;
    int K = S.size();
    vector<vector<ll>> dp(K+1, vector<ll>(2, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= K; i++) {
        int d = S[i-1]-'0';
        dp[i][0] = min(dp[i-1][0]+d, dp[i-1][1]+10-d);
        if (d <= 8) {
            dp[i][1] = min(dp[i-1][0]+d+1, dp[i-1][1]+9-d);
        }else {
            dp[i][1] = dp[i-1][1];
        }
    }
    cout << dp[K][0] << endl;
    return 0;
}
