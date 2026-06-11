#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> p(n),d;
    map<pair<ll,ll>,ll> mp;
    ll ans = 1;

    if(n == 1){
        cout << 1;
        return 0;
    }
    
    rep(i,n){
        cin >> p[i].first >> p[i].second;
    }

    rep(i,n){
        for(int j = i+1; j < n; j ++){
            d.push_back(make_pair(p[i].first - p[j].first, p[i].second - p[j].second));
            d.push_back(make_pair(p[j].first - p[i].first, p[j].second - p[i].second));
        }
    }

    rep(i,d.size()){
        if(mp.count(d[i]) == 0) mp[d[i]] = 1;
        else mp[d[i]] ++;
    }

    rep(i,d.size()) ans = max(ans,mp[d[i]]);

    cout << n - ans;




}