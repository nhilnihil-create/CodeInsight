#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    ll xo=v[1];
    for(ll i=2;i<=n;i++)
        xo=xo^v[i];
    for(ll i=1;i<=n;i++)
        cout<<(xo^v[i])<<" ";
}

    
