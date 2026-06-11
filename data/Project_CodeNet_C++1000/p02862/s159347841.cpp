#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const ll MOD = 1000000007;

ll fpow(ll a, ll b, ll p){
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll p){
    return fpow(a,p - 2, p);
}

ll nCk(ll n, ll k, ll p){
    vector<ll> fn(n + 1);
    fn[0] = 1;
    for(ll i = 1; i <= n; ++i){
        fn[i] = (fn[i - 1] * i) % p;
    }
    ll aux = (fn[k] * fn[n -k]) % p;
    ll pw = fpow(aux, p - 2, p) % p;
    ll ok = (pw * fn[n]) % p;
    return ok;
}

signed main(){
    io();
    ll x, y; cin >> x >> y;
    if((x + y) % 3){
        cout << 0 << '\n';
    }else{
        ll a = (x + x - y)/3;
        ll b = (y + y - x)/3;
        if(a < 0 || b < 0){
            cout << 0 << '\n';
        }else{
            cout << nCk(a+b, b, MOD) << '\n';
        }
    }
    return 0;
}