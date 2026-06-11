#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (K--) {
        if (*min_element(a + 1, a + n + 1) == n) break;
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++) {
            int l = max(1, i - a[i]), r = min(n, i + a[i]);
            b[l]++, b[r + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1], a[i] = b[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}