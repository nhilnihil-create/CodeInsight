#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define all(x) x.begin(),x.end()

const ll MOD = 1e9 + 7;

inline void normal(ll &a) { if (a >= MOD) a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) {normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) {normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; } //if MOD is prime, modPow(b, p % (MOD-1))
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int main() {
    int n; ll k; scanf("%d %lld", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    auto b = vector <int> (a, a + n);
    sort(b.begin(), b.end());

    vector <int> c;

    ll ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(all(c), a[i]);
        ll x = it - c.begin();
        
        auto jt = lower_bound(all(b), a[i]);
        ll y = jt - b.begin();


        ans = modAdd(ans, modMul(k, x));

        ll kmul = modMul(k, k - 1);
        kmul = modDiv(kmul, 2);

        ans = modAdd(ans, modMul(y, kmul));

        c.push_back(a[i]);
        sort(all(c));
    }

    printf("%lld\n", ans);
}