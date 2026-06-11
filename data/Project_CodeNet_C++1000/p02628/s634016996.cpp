#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define B begin()
#define E end()
using namespace std;
int main()
{
    ll n,k; cin>>n>>k;
    vector<ll>v;
    for(ll i=0;i<n;i++)
    {
        ll a; cin>>a; v.pb(a);
    }
    sort(v.B,v.E);
    ll s=0;
    for(ll i=0;i<k;i++) s+=v[i];
    cout<<s;
}
