#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;
const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<pll> x(n);
    rep(i,n){
        cin >> x[i].fi >> x[i].se;
    }
    sort(x.begin(),x.end());
    map<pll,ll> m;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            pll v;
            v.fi=x[j].fi-x[i].fi;
            v.se=x[j].se-x[i].se;
            m[v]++;
        }
    }
    ll cnt=0;
    for(auto x:m){
        cnt=max(cnt,x.se);
    }
    cout << n-cnt << endl;
    return 0;
}