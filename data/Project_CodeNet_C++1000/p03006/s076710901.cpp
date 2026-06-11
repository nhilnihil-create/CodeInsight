#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<pair<ll, ll> > v(n);
    rep(i, n){
        ll a, b;
        cin>>a>>b;
        v[i]=make_pair(a, b);
    }

    map<pair<ll, ll>, ll> mp;
    rep(i, n){
        for(int j=i+1;j<n;j++){
            ll a=(v[i].first-v[j].first);
            ll b=(v[i].second-v[j].second);
            if(a<0){
                a*=-1;
                b*=-1;
            }
            if(a==0){
                if(b<0) b*=-1;
            }
            mp[make_pair(a, b)]++;
        }
    }
    ll mx=0;
    for(auto p : mp){
        if(p.second>mx){
            mx=p.second;
        }
    }
    ll ans=n-mx;
    cout<<ans<<endl;
    return 0;
}