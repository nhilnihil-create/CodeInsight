#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
ll ksm(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll C(ll a,ll b)
{
    ll s1=1,s2=1;
    for(ll i=1;i<=b;i++) s2=s2*i%mod;
    for(ll i=a-b+1;i<=a;i++) s1=s1*i%mod;
    return s1*ksm(s2,mod-2)%mod;
}
int main()
{
    int x,y;cin>>x>>y;
    if((2*y-x)%3==0&&(2*y)-x>=0)
    {
        int a=(2*y-x)/3;
        int b=(2*x-y)/3;
        cout<<C(a+b,a)<<endl;
    }
    else
        cout<<0<<endl;
    return 0;
}
