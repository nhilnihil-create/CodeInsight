#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
// dp[i][j] = 和がiになるj項の数列ですべての項が3以上になるものの数
ll dp[2001][667] = {};
int main()
{
    int s;
    cin >> s;
    for(int i=3; i<=s; ++i){
        dp[i][1] = 1;
    }
    for(int j=2; j*3<=s; ++j){
        for(int i=3; i<=s; ++i){
            // dp[i][j] = \sum_{k>=3} dp[i-k][j-1]
            // = dp[i-3][j-1] + \sum_{k>=4} dp[i-k][j-1]
            // = dp[i-3][j-1] + \sum_{k>=3} dp[i-1-k][j-1]
            // = dp[i-3][j-1] + dp[i-1][j]
            dp[i][j] = (dp[i-3][j-1] + dp[i-1][j]) % MOD;
        }
    }
    ll ans = 0;
    for(int j=0; 3*j<=s; ++j)ans=(ans + dp[s][j]) % MOD;
    cout << ans << endl;
    return 0;
}
