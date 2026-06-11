#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
ll Power(ll a,ll b,ll p)
{
    ll res=1;
    while (b>0)
    {
        if (b%2!=0)
        res=((res%p)*(a%p))%p;
        a=((a%p)*(a%p))%p;
        b=b/2;
    }
    return res;
}
ll fac[10000005];
ll infac[10000005];
int main()
{
    ll x,y,mod=1000000007;
    scanf("%lld%lld",&x,&y);
    fac[0]=1;
    for (ll i=1;i<10000005;i++)
    fac[i]=((fac[i-1]%mod)*1LL*i)%mod;
    infac[10000004]=Power(fac[10000004],mod-2,mod);
    for (ll i=10000003;i>=0;i--)
    infac[i]=((infac[i+1]%mod)*1LL*(i+1)%mod)%mod;
    double m1=(2.0*x-y)/3.0;
    double n1=(2.0*y-x)/3.0;
    if (m1==(ll)m1 && n1==(ll)n1 && m1>=0 && n1>=0)
    {
        ll m=(ll)m1;
        ll n=(ll)n1;
        ll val=((((fac[m+n])*(infac[m]))%mod)*(infac[n]))%mod;
        printf("%lld\n",val);
    }
    else
    printf("0\n");
    return 0;
}