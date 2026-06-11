#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 2e3 + 5;
ll dp[maxn][maxn];

struct Node {
    int seq, val;
}a[maxn];

int cmp(Node a, Node b) {
    return a.val < b.val;
}

int main() {
    int len, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].val);
        a[i].seq = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = (ll)a[1].val * abs(a[1].seq - i);
    }

    int j;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            j = i + len - 1;
            dp[i][j] = max(dp[i + 1][j] + (ll)a[len].val * abs(a[len].seq - i), dp[i][j - 1] + (ll)a[len].val * abs(a[len].seq - j));
        }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}