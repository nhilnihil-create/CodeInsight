#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    vector<pair<ll,ll> >v;
    ll n; cin>>n;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb({i,n/i});
        }
    }
    ll x=v[v.size()-1].first;
    ll y=v[v.size()-1].second;
    cout<<(x-1)+(y-1);
}
