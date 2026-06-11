#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> v(n,vector<ll>(0));
    rep(i, n){
        ll x;
        cin >> x;
        v[x - 1].push_back(i);
    }
    ll ans = -1;
    ll rem = 0;
    ll p = -1;
    rep(i, n){
        if (v[i].size() == 0) break;
        ll m = 1e6;
        for (auto x : v[i]) {
            if (p < x) {
                m = min(x, m);
            }
        }
        if (m == 1e6) break;
        p = m;
        rem++;
        
    }
    if (rem  == 0) {
        ans = -1;
    }else {
        ans = n - rem;
    }
    cout << ans << endl;
    return 0;
}
