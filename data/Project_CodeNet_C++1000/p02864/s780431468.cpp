#include<iostream>
#include<cstring>
#include<cstdlib>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,K;
ll dp[310][310],a[310];
int main()
{
	cin>>n>>K;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    memset(dp,inf,sizeof(dp));
    dp[0][0]=0;
    ll ans=1e15;
    for(int i=1;i<=n;i++)
    for(int j=0;j<i;j++)
    for(int k=i-1;k>=0;k--)
    dp[i][k+1]=min(dp[i][k+1],dp[j][k]+max(0ll,a[i]-a[j]));
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    if(j>=n-K) ans=min(ans,dp[i][j]);
    cout<<ans;
    return 0;
}
