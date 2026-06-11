#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int n; scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += 1ll * i * (n - i + 1);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        ans -= 1ll * (n - v + 1) * u;
    }
    printf("%lld\n", ans);
    return 0;
}