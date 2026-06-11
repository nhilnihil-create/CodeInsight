#include<bits/stdc++.h>
const int mod=1e9+7;
typedef long long ll;
using namespace std;

ll ksm(ll a,ll b)
{
    ll ans=1;
    for(; b; b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans%mod;
}
int main()
{
    ll n;cin>>n;
    ll ans=(ksm(10,n)-ksm(9,n)-ksm(9,n)+ksm(8,n))%mod;
    cout<<(ans+mod)%mod;

    return 0;
}
