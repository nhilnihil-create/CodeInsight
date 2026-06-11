#include <bits/stdc++.h>

using namespace std;

int dp[10005];

int main() {
    int h, n;
    scanf("%d%d", &h, &n);

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        for (int j = 0; j < h; j++) {
            if (dp[j] == -1) continue;
            if (dp[min(h, j + x)] == -1 || dp[min(h, j + x)] > dp[j] + y) dp[min(h, j + x)] = dp[j] + y;
        }
    }

    printf("%d\n", dp[h]);
}
