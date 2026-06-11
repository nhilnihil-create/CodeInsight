#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 998244353;

ll pow_mod(ll a, ll n, ll p)
{
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*a%p;
        a = a*a%p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> d(n);
    for(i = 0;i < n;++i){
        cin >> d.at(i);
    }
    if(d.at(0) != 0){
        cout << 0 << endl;
        return 0;
    }
    sort(all(d));
    vector<pair<ll,ll>> a;
    ll ans = 1;
    ll num = 0;
    ll cnt = 0;
    for(i = 0;i < n;++i){
        if(d.at(i) == num) ++cnt;
        else{
            a.emplace_back(num, cnt);
            num = d.at(i);
            cnt = 1;
        }
    }
    a.emplace_back(num, cnt);
    if(a.at(0).second != 1){
        cout << 0 << endl;
        return 0;
    }
    for(i = 0;i < a.size();++i){
        if(a.at(i).first != i){
            cout << 0 << endl;
            return 0;
        }
    }
    for(i = 1;i < a.size();++i){
        ans *= pow_mod(a.at(i-1).second, a.at(i).second, MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}