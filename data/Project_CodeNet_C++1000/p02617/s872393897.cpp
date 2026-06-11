#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        ans += (i * (n - i + 1));
    }

    for (int i = 1; i < n; i++) {
        ll u, v; scanf("%lld %lld", &u, &v);
        if (u > v) swap(u, v);
        ans -= (u * (n - v + 1));
    }

    printf("%lld\n", ans);
}