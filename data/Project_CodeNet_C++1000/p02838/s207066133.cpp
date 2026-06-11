#include<bits/stdc++.h>
typedef unsigned long long ll;
ll mod=1e9+7;
using namespace std;
ll boom[100];
ll boom1[100];

ll ksm(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans%mod;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ll n;cin>>n;
    ll t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        ll temp=0;
        for(;t;t>>=1)
        {
            if(t&1) boom[temp]++;
            temp++;
        }
    }
    ll ans=0;
    for(int i=0;i<=64;i++)
    {
        if(boom[i]!=0)
            boom1[i]=n-boom[i];
    }
    for(int i=0;i<=64;i++)
    {
        ans=(ans+(ksm(2,i)*((boom[i]*boom1[i])%mod)%mod)%mod)%mod;
    }

    cout<<ans<<endl;
}
