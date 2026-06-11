#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007;

// dp[i][j] : 先頭からi桁目まで見たときの組み合わせ数。
//            j = 0 : i桁目まで一致
//            j = 1 : s未満であることが確定している
ll dp[100100][2]; 
int main() 
{
    string s;
    cin >> s;
    int n = s.size();

    rep(i,100100)rep(j,2) dp[i][j] = 0;
    dp[0][0] = 1;

    for (int i=1; i<=n; i++) {
        if (s[i-1] == '0') {
            // 合計が0
            (dp[i][0] += dp[i-1][0]) %= mod;
            (dp[i][1] += dp[i-1][1]) %= mod;
            // 合計が1
            (dp[i][1] += dp[i-1][1] * 2 % mod) %= mod;
        } else { // == '1'
            // 合計が0
            (dp[i][1] += dp[i-1][0] + dp[i-1][1]) %= mod;
            // 合計が1
            (dp[i][0] += dp[i-1][0] * 2 % mod) %= mod;
            (dp[i][1] += dp[i-1][1] * 2 % mod) %= mod;
        }
    }

    ll ans = dp[n][0] + dp[n][1];
    ans %= mod;
    cout << ans << endl;

    return 0;
}
