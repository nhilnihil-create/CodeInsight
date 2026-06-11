#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 2e5 + 3;
const ll mo = 1e9 + 7;

int n, k, p[maxn], pl;
bool isc[maxn];
ll mu[maxn], cnt[maxn];

ll mpow(ll u, ll k) {
    ll ans = 1;
    for(; k > 0; k >>= 1) {
        if(k & 1)
            ans = ans * u % mo;
        u = u * u % mo;
    }
    return ans;
}

int main() {
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(!isc[i]) {
            p[pl++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pl && i * (ll)p[j] < maxn; ++j) {
            isc[i * p[j]] = true;
            mu[i * p[j]] = -mu[i];
            if(i % p[j] == 0) {
                mu[i * p[j]] = 0;
                break;
            }
        }
    }
    scanf("%d%d", &n, &k);
    ll ans = 0;
    for(int i = 1; i <= k; ++i) {
        ll w = i - cnt[i];
        ans = (ans + w % mo * mpow(k / i, n)) % mo;
        for(int j = 1; i * (ll)j <= k; ++j) {
            cnt[i * j] += w;
        }
    }
    ans = (ans + mo) % mo;
    printf("%lld\n", ans);
    return 0;
}