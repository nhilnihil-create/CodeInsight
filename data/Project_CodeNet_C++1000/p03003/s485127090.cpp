#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main()
{
    int n, m;
    cin>>n>>m;
    vector<int> s(n);
    vector<int> t(m);
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<m; i++) cin>>t[i];
    vector<vector<int> > dp(n+1, vector<int>(m+1, 1));
    // int dp[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // if(i == 0 || j == 0){ dp[i][j] = 1; continue; }
            if(s[i-1] == t[j-1])
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
                else
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
            // if(s[i-1] == t[j-1])
            //     dp[i][j] = (dp[i][j]  +  1)%mod;
        }
    }
    cout<<dp[n][m];
}
