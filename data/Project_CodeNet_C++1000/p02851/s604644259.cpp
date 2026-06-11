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
    vector<ll> a(n);
    rep(i,n){
        cin >> a.at(i);
        --a.at(i);
    }
    vector<ll> sum(n+1,0);
    for(i = 1;i <= n;++i){
        sum.at(i) = a.at(i-1);
    }
    rep(i,n){
        sum.at(i+1) += sum.at(i);
        sum.at(i+1) %= k;
    }
    map<ll, vector<ll>> spare;
    for(i = 0;i <= n;++i){
        spare[sum.at(i)].push_back(i);
    }
    ll ans = 0;
    for(auto x:spare){
        auto y = x.second;
        ll m = y.size();
        for(i = 0;i < m;++i){
            ll now = y.at(i);
            ll ind = lower_bound(all(y), now + k) - y.begin() - 1;
            ans += ind - i;
        }
    }
    cout << ans << endl;

    return 0;
}