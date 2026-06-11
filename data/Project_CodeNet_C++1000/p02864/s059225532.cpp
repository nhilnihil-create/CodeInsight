#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1e7+5+5e6;
using namespace std;
const ll INF=1e15+7;
const ll mod=998244353;
ll n,m,p;
ll dp[305][305];
ll num[maxn];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    for(int i=0;i<=n;i++)
        for(int k=0;k<=n;k++) dp[i][k]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n-m;k++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][k]=min(dp[i][k],dp[j][k-1]+max(0ll,num[i]-num[j]));
            }
        }
    }
    //
    ll res=INF;
    for(int i=1;i<=n;i++)
        res=min(res,dp[i][n-m]);
    if(m==n) printf("0\n");
    else
        printf("%lld\n",res);
    return 0;
}