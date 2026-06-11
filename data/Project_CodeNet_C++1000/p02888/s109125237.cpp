#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; ++i){
        cin >> v[i];
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    for(ll i = n - 1; i >= 0; --i){
        for(ll j = i - 1; j >= 0; --j){
            vector<ll>::iterator up;
            up = upper_bound (v.begin(), v.end(), v[i] - v[j]);
            ll pos = up - v.begin();
            ans += max(j - pos, ll(0));
        }
    }
    cout << ans;
}
