#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;

int a[maxn];
int b[maxn];
int dp[3010][3010][2];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t-1;j++)
        {
            if(j>=a[i])
            {
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-a[i]][0]+b[i]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]+b[i]);
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-a[i]][1]+b[i]);
            }
            else
            {
                dp[i][j][0]=dp[i-1][j][0];
                dp[i][j][1]=max(dp[i-1][j][0]+b[i],dp[i-1][j][1]);
            }
        }
    }
    cout<<dp[n][t-1][1]<<'\n';




}
