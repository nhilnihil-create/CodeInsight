#include<bits/stdc++.h>
#define nl '\n'
#define dbg(a) cout<<#a<<"="<<a<<nl
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ii pair<int,int>
#define vi vector<int>
#define md 998244353

using namespace std;

int solve()
{

    ll n;
    cin>>n;
    ll x=0;
    for(ll i=1;i<=n;i++)
    {
        x+=i*(n-i+1);
    }
    ll y=0;
    for(int i=1;i<n;i++)
    {
        ll a, b;
        cin>>a>>b;
        if(a>b) swap(a, b);
        y+=a*(n-b+1);
    }
    cout<<x-y<<endl;

    return 0;
}

int main()
{
    fast;
    solve();

    return 0;
}
