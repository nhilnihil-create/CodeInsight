#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mod = 1e9 + 7;

ll calc(ll b, ll exp){
    ll result = 1;
    while(exp > 0){
        if(exp % 2 == 1){
            result = (result * b) % mod;
        }
        exp >>= 1;
        b = (b * b) % mod;
    }
    return result;
}

ll diver(ll a, ll b) {
    return a*calc(b, mod-2)%mod;
}

ll choose(ll n, ll k) {
    ll res = 1;
    for (ll i = n-k+1; i <= n; ++i) {
        res = (res*i)%mod;
    }
    for (ll i = 2; i <= k; ++i) {
        res = diver(res, i);
    }
    return res%mod;
}

int main(){
    ll n, a, b, ans, apow, bpow;
    cin >> n >> a >> b;
    ans = calc(2, n) - 1;
    ans += mod - choose(n, a);
    ans %= mod;
    ans += mod - choose(n, b);
    ans %= mod;
    cout << ans;
    return 0;
}
