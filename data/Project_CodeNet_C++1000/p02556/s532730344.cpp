#include <bits/stdc++.h>
#define NMAX 200005

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
typedef pair<ll,ll> pll;
pll pmin[4],v[NMAX];
ll c[4]={INT_MIN,INT_MIN,INT_MIN,INT_MIN},mul[2]={1,-1};
ll manhattan(pll a, pll b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        for(ll j=0;j<4;j++){
            ll d=v[i].first*mul[j&1]+v[i].second*mul[j<2];
            if(d>c[j]){
                c[j]=d;
                pmin[j]=v[i];
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<4;j++){
            ans=max(ans,manhattan(v[i],pmin[j]));
        }
    }
    cout<<ans;
    return 0;
}
