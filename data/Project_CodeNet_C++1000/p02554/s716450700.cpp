#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define inf 2e18
#define ull unsigned long long
#define pi acos(-1.0)
#define mod 1000000007
#define lop0(n) for(ll i=0;i<n;i++)
#define lopj(n) for(ll j=0;j<n;j++)
#define lop1(n) for(ll i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
ll Set(ll N,ll pos){ return N=N | (1LL<<pos); }
ll reset(ll N,ll pos){ return N= N & ~(1LL<<pos); }
bool check(ll N,ll pos){ return (bool)(N & (1LL<<pos)); }
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2) res=(res*a)%mod,n--;
        else a=(a*a)%mod,n/=2;
    }
    return res;
}
main()
{
   ll n;
   cin>>n;
   ll ans=power(10,n);
   ans+=mod;
   ans%=mod;
   ans-=(2*power(9,n));
   ans+=mod;
   ans%=mod;
   ans+=power(8,n);
   ans+=mod;
   ans%=mod;
   cout<<ans<<endl;
}

