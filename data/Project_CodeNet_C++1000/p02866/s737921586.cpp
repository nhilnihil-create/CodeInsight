#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 998244353;

ll mod_pow(ll a, ll n){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    map<ll, ll> mp;
    bool f = false;
    ll mx = 0;
    rep(i, 0, N){
        ll d; cin >> d;
        mp[d]++;
        mx = max(mx, d);
        if(i != 0 && d == 0) f = true;
        if(i == 0 && d != 0) f = true;
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep(i, 1, mx+1){
        if(mp.count(i) == 0){
            cout << 0 << endl;
            return 0;
        }
        ans *= mod_pow(mp[i-1], mp[i]);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}