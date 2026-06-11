#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
const int N=3005;
int n,s;
ll dp[N];
int main()
{
    ll inv2=mod-mod/2;
    dp[0]=1;
    scanf("%d%d",&n,&s);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        for(int j=s;j>=x;j--)
            dp[j]=(dp[j]+dp[j-x]*inv2)%mod;
    }
    for(int i=1;i<=n;i++) dp[s]=dp[s]*2%mod;
    printf("%lld\n",dp[s]);
}