#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int mx = 2e5 + 9;

int n;
ll k;
ll a[mx];

ll ceill(ll x, ll y) {
    return (x + y - 1) / y;
}

bool ok(ll x) {
    ll ttl = 0;
    for (int i = 0; i < n; i++) {
        ttl += ceill(a[i], x);
    }

    return (ttl - n <= k);
}

int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    ll ans = *max_element(a, a + n);
    ll lo = 1, hi = 2e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%lld\n", ans);
}