#include <bits/stdc++.h>

using namespace std;

char A[110][110];
int dp[110][110];
int main()
{
    int n , m ; cin >> n >> m ;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> A[i][j];
    for(int i = 2 ; i <= max(n,m) ; ++i) dp[i][0] = dp[0][i] = 1e9;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(A[i][j]=='.') dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
            else dp[i][j] = min(dp[i-1][j] + (A[i-1][j]!='#'),dp[i][j-1] + (A[i][j-1]!='#'));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}