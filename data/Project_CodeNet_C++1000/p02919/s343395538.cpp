#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> pos(n);
    rep(i,n){
        ll p;
        cin >> p;
        --p;
        pos.at(p) = i;
    }
    ll ans = 0;
    multiset<ll> ms;
    ms.insert(-1),ms.insert(-1),ms.insert(n),ms.insert(n);
    for(i = n-1;i >= 0;--i){
        ll now = pos.at(i);
        auto it = ms.lower_bound(now);
        ll r = *it;
        ll rr = *(++it);
        --it;   --it;
        ll l = *it;
        ll ll = *(--it);
        ans += (i+1)*(r - now)*(l - ll);
        ans += (i+1)*(rr - r)*(now - l);

        ms.insert(now);
    }

    cout << ans << endl;

    return 0;
}