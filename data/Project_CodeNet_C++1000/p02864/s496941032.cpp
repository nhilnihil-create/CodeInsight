#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=305;
int n,k,a[N];
ll dp[N][N][N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,inf,sizeof(dp));
    dp[0][0][0]=0;
    ll ans=1e15;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
        for(int k=0;k<i;k++)
        {
            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
            dp[i][i][k+1]=min(dp[i][i][k+1],dp[i-1][j][k]+max(0,a[i]-a[j]));
        }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        if(j>=n-k) ans=min(ans,dp[n][i][j]);
    printf("%lld\n",ans);
}
