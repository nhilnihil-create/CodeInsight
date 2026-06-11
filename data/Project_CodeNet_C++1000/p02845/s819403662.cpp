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
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    const ll MOD = 1e9 + 7;
    vector<ll> color(3,0);
    ll ans = 1;
    for(i = 0;i < n;++i){
        vector<ll> ichi;
        rep(j,3){
            if(color.at(j) == a.at(i)) ichi.push_back(j);
        }
        if(ichi.size() == 0){
            cout << 0 << endl;
            return 0;
        }else if(ichi.size() == 3){
            ++color.at(2);
            ans *= 3;
        }else if(ichi.size() == 2){
            ++color.at(1);
            ans *= 2;
        }else if(ichi.size() == 1){
            auto x = lower_bound(all(color), a.at(i));
            ++*x;
        }
        sort(all(color));
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}