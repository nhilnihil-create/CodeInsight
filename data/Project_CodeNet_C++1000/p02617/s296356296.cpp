#include <stdio.h>
int main() {
    int n, u, v;
    scanf("%i", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * 1ll * (n - i + 1);
    }
    for (int i = 1; i < n; i++) {
        scanf("%i%i", &u, &v);
        if (u > v) {
            u += v;
            v = u - v;
            u -= v;
        }
        ans -= u * 1ll * (n - v + 1);
    }
    printf("%lli", ans);
}
