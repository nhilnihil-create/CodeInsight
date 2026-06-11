#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n, p;
    string s;
    cin >> n >> p >> s;
    if(p == 2 || p == 5){
        ll ans = 0;
        for(i = n-1;i >= 0;--i){
            ll tmp = s.at(i) - '0';
            if(tmp%p == 0) ans += i+1;
        }
        cout << ans << endl;
        return 0;
    }
    map<ll,ll> mp;
    ll spare = 0;
    ll rui = 1;
    ll ans = 0;
    for(i = n-1;i >= 0;--i){
        ll digit = s.at(i) - '0';
        spare += rui*digit;
        spare %= p;
        ans += mp[spare];
        if(spare == 0) ++ans;

        ++mp[spare];

        rui = rui*10%p;
    }

    cout << ans << endl;

    return 0;
}