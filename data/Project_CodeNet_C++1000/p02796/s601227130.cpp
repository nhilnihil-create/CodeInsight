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
    vector<ll> x(n);
    vector<ll> l(n);
    for(i = 0;i < n;++i){
        cin >> x.at(i) >> l.at(i);
    }
    vector<pair<ll,ll>> y(n);
    for(i = 0;i < n;++i){
        y.at(i).first = x.at(i) + l.at(i);
        y.at(i).second = x.at(i) - l.at(i);
    }
    sort(all(y));
    ll ans = 0;
    ll hazi = -1e10;
    for(i = 0;i < n;++i){
        if(y.at(i).second >= hazi){
            ++ans;
            hazi = y.at(i).first;
        }
    }
    cout << ans << endl;

    return 0;
}