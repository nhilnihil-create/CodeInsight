#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll ans,cnt[100005],n,k;

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=k;i>=1;i--)
    { 
        cnt[i]=fp(k/i,n);
        for(int j=2*i;j<=k;j+=i) 
        {
            cnt[i]-=cnt[j];
            if(cnt[i]<0) cnt[i]+=mod;
        }
        ans=(ans+i*cnt[i])%mod;
    }
    printf("%lld",ans);
    return 0;
}