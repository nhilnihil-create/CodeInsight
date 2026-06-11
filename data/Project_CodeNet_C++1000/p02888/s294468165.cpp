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
    vector<ll> l(n);
    rep(i,n) cin >> l.at(i);
    sort(all(l));
    ll ans = 0;
    for(i = 0;i < n-1;++i){
        for(j = i+1;j < n;++j){
            ll tmp = l.at(i) + l.at(j);
            ll ind = lower_bound(all(l), tmp) - l.begin();
            ans += ind - j - 1;
        }
    }
    cout << ans << endl;

    return 0;
}