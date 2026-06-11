#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;

int a[MAXN];

int cmp(int a, int b) {
    return a > b;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n, cmp);
    LL ans = a[0];
    for (int i = 1; i < n / 2; i++)
        ans += 2 * a[i];
    if (n % 2 == 1) ans += a[n / 2];
    printf("%lld\n", ans);
    return 0;
}
