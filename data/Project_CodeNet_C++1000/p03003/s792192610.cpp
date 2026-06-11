#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3+10;
const int MOD = 1e9+7;

int s[MAX], t[MAX];
long long dp[MAX][MAX];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;++i)
        cin >> s[i];
    
    for(int i=1;i<=m;++i)
        cin >> t[i];
    
    for(int i=0;i<=max(n,m);++i)
        dp[i][0] = dp[0][i] = 1;
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(s[i] == t[j])
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % MOD;
    
    cout << (dp[n][m] + MOD) % MOD << '\n';

    return 0;
}
