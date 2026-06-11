#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

inline long long mpow(long long b, long long ex){
    if (b==1)return 1;
    long long r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

ll modinv(ll a) {
    return mpow(a, mod-2);
}

ll fact(ll a, ll n) {
    ll num = 1, den = 1;
    for (int i = n; i >= n-a+1; i--) num = (num * i) % mod;
    for (int i = a; i >= 1; i--) den = (den * i) % mod;

    return (num * modinv(den)) % mod;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = ((mpow(2, n)-1 - (fact(a, n) + fact(b, n)) % mod) + mod) % mod;
    cout << ans << endl;
}