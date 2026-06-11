#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define pb push_back
#define mk make_pair
#define ull unsigned long long
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    fastIO;
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    map<ll,ll>m;
    m.insert({1,300000});
    m.insert({2,200000});
    m.insert({3,100000});
    if(x>=1 && x<=3)
    {
        ans+=m[x];
    }
    if(y>=1 && y<=3)
    {
        ans+=m[y];
    }
    if(x==y && x==1)
    {
        ans+=400000;
    }
    cout<<ans<<'\n';
    return 0;
}