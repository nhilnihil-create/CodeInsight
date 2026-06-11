#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, a[2009], b[2009];
ll dp[2009][2009], mod=1e9+7;
int main()
{
    IO;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    dp[0][0]=1;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=((dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod+mod)%mod;
            if(a[i]==b[j])
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
        }
    cout<<dp[n][m];
}
