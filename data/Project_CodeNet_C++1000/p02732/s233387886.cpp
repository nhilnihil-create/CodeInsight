#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    rep(i, n){
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()){
            mp[a[i]] = 1;
        }else{
            mp[a[i]] += 1;
        }
    }

    ll sum=0;
    for (auto x: mp){
        sum += (x.second) * (x.second-1)/2;
    }

    rep(i, n){
        ll ans = sum - (mp[a[i]] - 1);
        cout << ans << endl;
    }


    return 0;
}
