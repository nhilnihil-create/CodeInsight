#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int mx = 1e5 + 9;
const ll MOD = 1e9 + 7;

inline void normal(ll &a) { if (a >= MOD) a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) {normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) {normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; } //if MOD is prime, modPow(b, p % (MOD-1))
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll cnt[mx];

int main() {
    ll n, k; scanf("%lld %lld", &n, &k);

    ll ans = 0;
    for (ll x = k; x > 0; x--) {
        ll d = k / x;
        cnt[x] = modPow(d, n);

        ll y = 2 * x;
        while (y <= k) {
            cnt[x] = modSub(cnt[x], cnt[y]);
            y += x;
        }

        ans = modAdd(ans, modMul(cnt[x], x));
    }

    printf("%lld\n", ans);
}