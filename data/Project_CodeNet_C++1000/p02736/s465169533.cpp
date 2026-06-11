#include <bits/stdc++.h>
using namespace std;

int n, x[1000010], a[1000010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &x[i]);
    }
    for (int i = 1; i < n; i++) {
        a[i] = abs(x[i] - x[i + 1]);
    }
    n--;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        flag &= (a[i] == 0 || a[i] == 2);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (flag && a[i] == 2) a[i] = 1;
        if (((n - 1) & (i - 1)) == (i - 1)) (ans += a[i]) %= 2;
    }
    if (flag && ans) ans = 2;
    printf("%d\n", ans);
    return 0;
}