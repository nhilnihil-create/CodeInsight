#include<bits/stdc++.h>
using namespace std;
#define l long int 
#define ll long long int 
vector<int>adj[1000001];
int vis[1000001];
int n=2005;
#define mod 1000000007 
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>dp(4,vector<ll>(n));
    ll x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        dp[0][i]=x+y;
        dp[1][i]=-x+y;
        dp[2][i]=x-y;
        dp[3][i]=-x-y;
    }
    for(int i=0;i<4;i++)
    {
        sort(dp[i].begin(),dp[i].end());
    }
    ll ans=-1e18;
    for(int i=0;i<4;i++)
    {
        ans=max(ans,dp[i][n-1]-dp[i][0]);
    }
    cout<<ans<<"\n";
    return 0;
}