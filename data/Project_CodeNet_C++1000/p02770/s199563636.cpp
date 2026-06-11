#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005;
ll k,q,d[N],a[N];
int main()
{
    scanf("%lld%lld",&k,&q);
    for(ll i=0;i<k;i++) scanf("%lld",&d[i]);
    while(q--)
    {
        ll n,x,mod;
        scanf("%lld%lld%lld",&n,&x,&mod);
        if(n<=k)
        {
            a[0]=x%mod;
            for(int i=1;i<n;i++)
                a[i]=(a[i-1]+d[i-1])%mod;
            int ans=0;
            for(int i=0;i<n-1;i++)
                if(a[i]<a[i+1]) ans++;
            printf("%d\n",ans);
            continue;
        }
        ll sum=0;
        for(ll i=0;i<k;i++) sum+=d[i]%mod;
        ll s=x%mod+(n-1)/k*sum;
        ll t=(n-1)%k;
        for(ll i=0;i<t;i++)
            s+=d[i]%mod;
        ll ans=n-1-s/mod;
        for(ll i=0;i<k;i++)
            if(d[i]%mod==0)
            {
                ll sum=(n-1-i)/k-((n-1-i)%k==0);
                ans-=sum;
                if(i<n-1) ans--;
            }
        printf("%lld\n",ans);
    }
}
