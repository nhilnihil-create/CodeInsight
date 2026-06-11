#include <stdio.h>
int main() {
    int n, i;
    long long ans = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        if (i % 3 && i % 5) ans += i;
    }
    printf("%lld\n", ans);
    return 0;
}
