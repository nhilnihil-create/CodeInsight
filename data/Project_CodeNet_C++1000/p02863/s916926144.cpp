#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=1e6+10;
const int mod=1e9+7;
const double pi=3.1415926535;
int w[3005],v[3005];
int dp[3005][3005][2];




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t-1;j++)
        {
            for(int x=0;x<=1;x++)
            {
                if(x==0)
                {
                    if(j>=w[i])
                    {
                        dp[i][j][x]=max(dp[i-1][j][x],dp[i-1][j-w[i]][x]+v[i]);
                    }
                    else
                    {
                        dp[i][j][x]=dp[i-1][j][x];
                    }
                }
                else
                {
                    dp[i][j][x]=max(dp[i-1][j][x],dp[i-1][j][0]+v[i]);
                    if(j>=w[i])
                    {
                        dp[i][j][x]=max(dp[i][j][x],dp[i-1][j-w[i]][x]+v[i]);
                    }
                }
            }
        }
    }
    cout<<dp[n][t-1][1]<<'\n';






}
