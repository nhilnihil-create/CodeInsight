#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
long long a[maxn], b[maxn], mx[maxn];

int main() {
    scanf("%d", &n), n++;
    for (int i = mx[1] = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (n == 1) printf("%d\n", a[i] == 1 ? 1 : -1), exit(0);
        if (i == 1 && a[i]) printf("-1\n"), exit(0);
        if (i == 1) continue;
        mx[i] = min(i > 60 ? (long long)2e18 : (1LL << (i - 1)), mx[i - 1] << 1) - a[i];
        if (mx[i] < 0) printf("-1\n"), exit(0);
    }
    long long ans = 0;
    for (int i = n; i; i--) {
        a[i] += min(mx[i], a[i + 1]), ans += a[i];
    }
    printf("%lld\n", ans);
    return 0;
}