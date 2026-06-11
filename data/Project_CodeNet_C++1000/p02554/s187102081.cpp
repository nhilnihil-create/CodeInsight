#include <bits/stdc++.h>
#define        ll     long long int
using namespace std;
ll mod=1e9+7;
int add(ll x,ll y)
{
    return ((x%mod)+(y%mod))%mod;
}
int minu(ll x,ll y)
{
    return (((x-y)%mod)+mod)%mod;
}
int nine(ll n)
{
    ll ans=1;
    while(n>0)
    {
        ans=((ans%mod)*(9%mod))%mod;
        n--;
    }
    return ans;
}
int ten(ll n)
{
    ll ans=1;
    while(n>0)
    {
        ans=((ans%mod)*(10%mod))%mod;
        n--;
    }
    return ans;
}
int eight(ll n)
{
    ll ans=1;
    while(n>0)
    {
        ans=((ans%mod)*(8%mod))%mod;
        n--;
    }
    return ans;
}
int solve(ll n)
{
    ll m=ten(n);
    ll z=nine(n);
    ll l=eight(n);
    return minu(add(m,l),add(z,z));
}
int main()
{
    ll n;
        cin>>n;
        ll x=solve(n);
        cout<<x<<endl;
    return 0;
}
