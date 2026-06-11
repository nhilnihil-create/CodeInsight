//
// Created by munaiyi on 2020/3/28.
//
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
long long sum[maxn];
int a[maxn];

int main() {
    int n, m, v, p;
    scanf("%d%d%d%d", &n, &m, &v, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n, [](int x, int y) -> bool {
        return x < y;
    });
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (n - i + 1 <= p) break;
        if (a[i] + m < a[n - p + 1]) {
            ans--;
            continue;
        }
        int tv = v - i - (p - 1);
        if (tv <= 0) {
            break;
        }
        long long tmp = sum[n - p + 1] - sum[i] + 1LL * m * tv;
        int chu = n - p + 1 - i;
        tmp = (tmp + chu - 1) / chu;
        if (a[i] + m >= tmp) {
            break;
        }
        ans--;

    }
    printf("%d\n", ans);
    return 0;
}
