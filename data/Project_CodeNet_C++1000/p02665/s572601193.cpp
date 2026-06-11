#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    ll a[n + 5];
    ll c[n + 5];
    for (int i = 0; i <= n; i++) scanf("%lld", &a[i]);

    if (n == 0) {
        if (a[0] != 1) puts("-1");
        else puts("1");
        return 0;
    } else {
        if (a[0] != 0) {
            puts("-1");
            return 0;
        }
    }

    c[n] = a[n];
    for (int i = n - 1; i > 0; i--) {
        c[i] = a[i] + c[i + 1];
    }

    ll ans = 1;
    ll b = 1;
    for (int i = 1; i <= n; i++) {
        ll bd = 2 * b;
        bd = min(bd, c[i]);
        if (a[i] > bd) {
            puts("-1");
            return 0;
        }

        ans += bd;
        b = bd - a[i];
    }

    printf("%lld\n", ans);
}