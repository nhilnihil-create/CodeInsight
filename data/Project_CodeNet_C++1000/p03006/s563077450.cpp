#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver(ll *x,ll *y,ll n)
{
    map<pair<ll,ll>,ll> mp;
    rep(i,0,n){
        rep(j,0,n){
            if(i==j)continue;
            ll px=x[j]-x[i],py=y[j]-y[i];
            if(mp.count(make_pair(px,py))==0){
                mp.emplace(make_pair(px,py),1);
            }
            else
            {
                ++mp[make_pair(px,py)];
            }
        }
    }
    ll max=0;
    for(auto e:mp){
        if(e.second>max){max=e.second;}
    }
    return n-max;

}
int main()
{
cin.tie(0);
ios::sync_with_stdio(false);
ll n;
cin>>n;
ll x[n],y[n];
rep(i,0,n)cin>>x[i]>>y[i];
cout<<solver(x,y,n)<<endl;
}