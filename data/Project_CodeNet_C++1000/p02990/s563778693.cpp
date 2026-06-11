#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
ll f[N];
ll ksm(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
void fac(int n)
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++) f[i]=f[i-1]*i%mod;
}
ll C(ll a,ll b)
{
    return f[a]*ksm(f[b],mod-2)%mod*ksm(f[a-b],mod-2)%mod;
}
int main()
{
    fac(2100);
    ll n,k;cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        if(i>n-k+1) cout<<0<<endl;
        else
        {
            cout<<C(n-k+1,i)*C(k-1,i-1)%mod<<endl;
        }
 
    }
    return 0;
}