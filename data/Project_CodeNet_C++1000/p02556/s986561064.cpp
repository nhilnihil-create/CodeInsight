#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    ll mx1=-1e10,mn1=1e10,mn2=1e10,mx2=-1e10;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y; 
        mx1=max(mx1,x+y);
        mn1=min(mn1,x+y);
        mx2=max(mx2,x-y);
        mn2=min(mn2,x-y);
    }
    cout<<max(mx1-mn1,mx2-mn2);
}

int main()
{
    IOS
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++) solve();
    return 0;
}

