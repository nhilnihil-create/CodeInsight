#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1,0);
    rep(i,n){
        cin >> a.at(i+1);
        --a.at(i+1);
    }
    for(i = 0;i < n;++i){
        a.at(i+1) += a.at(i);
        a.at(i+1) %= k;
    }
    map<ll, vector<ll>> spare;
    for(i = 0;i <= n;++i){
        spare[a.at(i)].push_back(i);
    }
    ll ans = 0;
    for(auto x:spare){
        ll m = x.second.size();
        for(i = 0;i < m;++i){
            ll now = x.second.at(i);
            ll ind = lower_bound(all(x.second), now + k) - x.second.begin() - 1;
            ans += ind - i;
        }
    }
    cout << ans << endl;

    return 0;
}
