#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll task(ll y, ll k)
{
    ll x = 1;
    for(ll i=0; i<k; i++)
    {
        x=x*y%mod;
    }
    return x;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = task(10,n) - task(9,n) - task(9,n) + task(8,n);
    ans%=mod;
    if(ans < 0)
    ans=(ans+mod)%mod;
    cout << ans;
    return 0;
}