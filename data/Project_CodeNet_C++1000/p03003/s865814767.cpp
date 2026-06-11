#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(m);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int j=0; j<m; j++) cin >> t[j];

    vector<vector<long long int>> dp(n+1, vector<long long int>(m+1));// dp[i+1][j+1] = #(pairs of CS upto s[i], t[j])
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=0; j<=m; j++) dp[0][j] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j];
            if(s[i] == t[j]) dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] = (dp[i+1][j+1] % MOD + MOD) % MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}