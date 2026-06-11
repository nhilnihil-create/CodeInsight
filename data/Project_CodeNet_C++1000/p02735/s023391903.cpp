#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int> (m+1 , 100000));
    vector<string> str(n);
    for(int i=0;i<n;i++)
        cin>>str[i];

    dp[1][1] = (str[n-1][m-1] == '#') ? 1: 0;

    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(i == 1 && j == 1)
                continue;
            else if( i == 1)
                dp[i][j] = dp[i][j-1] + (str[i-1][j-2] == '#' && str[i-1][j-1] == '.');
            else if( j == 1)
                dp[i][j] = dp[i-1][j] + (str[i-2][j-1] == '#' && str[i-1][j-1] == '.');
            else
            {
                dp[i][j] = min( dp[i][j], dp[i][j-1] + (str[i-1][j-2] == '#' && str[i-1][j-1] == '.'));
                dp[i][j] = min( dp[i][j], dp[i-1][j] + (str[i-2][j-1] == '#' && str[i-1][j-1] == '.'));
            }
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;                          
}
