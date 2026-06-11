#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int t;
int n,m;
int c[3005],w[3005];
ll dp[3005][3005];
ll _dp[3005][3005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j) dp[i][j] = dp[i-1][j];
        for(int j=m;j>=c[i];--j)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
        }
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<=m;++j) _dp[i][j] = _dp[i+1][j];
        for(int j=m;j>=c[i];--j)
        {
            _dp[i][j] = max(_dp[i+1][j],_dp[i+1][j-c[i]]+w[i]);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<m;++j)
        {
            ans = max(ans,dp[i-1][j]+w[i]+_dp[i+1][m-1-j]);
        }
    }
    printf("%lld\n",ans);
}
