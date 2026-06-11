#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll fp(ll base, ll pw) {
    if (base == 0) return 0;
    if (pw == 1) return base;
    if (pw == 0) return 1;
    ll ret = fp(base, pw / 2) % mod;
    ret = ((ret % mod) * (ret % mod)) % mod;
    if (pw % 2) ret = ((base % mod) * (ret % mod)) % mod;
    return ret;
}
const int N = 2e5 + 5;
ll fact[N];
ll calc(ll a, ll b) {
    ll ret = 1;
    for (ll i = a; i > a - b; i--) ret = ((ret % mod) * (i % mod)) % mod;
    ret = ((ret % mod) * fp(fact[b] % mod, mod - 2)) % mod;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    ll res = fp(2, n) - 1;
    res += mod;
    res %= mod;
    fact[1] = 1;
    for (int i = 2; i <= 2e5; i++) fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
    res -= calc(n, a);
    res += mod;
    res %= mod;
    res -= calc(n, b);
    res += mod;
    res %= mod;
    cout << res;
    return 0;
}
