#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    ll a[n + 5];
    for (int i = 0; i <= n; i++) scanf("%lld", &a[i]);

    ll c[n + 5];
    c[n] = a[n];
    for (int i = n - 1; i >= 0; i--) {
        c[i] = a[i] + c[i + 1];
    }

    if (n == 0) {
        if (a[0] > 1) {
            puts("-1");
            return 0;
        }

        printf("%lld\n", a[0]);
        return 0;
    } else {
        if (a[0] != 0) {
            puts("-1");
            return 0;
        }
    }

    ll last = 1;
    ll ans = 1;

    for (int i = 1; i <= n; i++) {
        if (last < 0) {
            ans = -1;
            break;
        }

        ll cur = 2 * last;
        cur = min(cur, c[i]);

        if (cur - a[i] >= 0) {
            ans += cur;
            last = cur - a[i];
        } else {
            ans = -1;
            break;
        }
    }

    printf("%lld\n", ans);
}