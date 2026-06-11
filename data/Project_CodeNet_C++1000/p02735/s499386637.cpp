#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    int dp[n][m];
    for (int i=0; i<n; i++)for (int j=0; j<m; j++)dp[i][j] = 10000;
    int cnt = 0;
    if (v[0][0] == '#')dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i=1; i<m; i++){
        if (v[0][i] == '#' && v[0][i-1]=='.')dp[0][i] = dp[0][i-1] + 1;
        else dp[0][i] = dp[0][i-1];
    }
    for (int i=1; i<n; i++){
        if (v[i][0] == '#' && v[i-1][0]=='.')dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = dp[i-1][0];
    }
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            if (v[i][j] == '#' && v[i-1][j]=='.')dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            else dp[i][j] = min(dp[i-1][j], dp[i][j]);
            if (v[i][j] == '#' && v[i][j-1] == '.')dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            else dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[n-1][m-1]<<endl;

}