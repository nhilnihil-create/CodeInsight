#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll mod = 1000000007;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a) {
    return modpow(a, mod - 2);
}

ll choose(ll a, ll b){
    if(b == 0) return 1;
    ll x = 1;
    rep(i, b){
        x *= (a - i);
        x %= mod;
        x *= modinv(b-i);
        x %= mod;
    }
    return x;
}
int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, k){
        ll ans;
        ans = choose(n - k + 1, i + 1);
        ans *= choose(k - 1, i);
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}