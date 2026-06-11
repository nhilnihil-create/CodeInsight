#include <bits/stdc++.h>

using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;

int n, m;
char niz[maxn][maxn];
int dp[maxn][maxn];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", niz+i);

    dp[0][0] = (niz[0][0] == '#');
    for (int i = 0; i < n; i++) {
        for (int j = (i == 0); j < m; j++) {
            dp[i][j] = inf;
            if (i > 0) dp[i][j] = dp[i - 1][j] + (niz[i - 1][j] == '.' && niz[i][j] == '#');
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (niz[i][j - 1] == '.' && niz[i][j] == '#'));
        }
    }
    printf("%d\n", dp[n - 1][m - 1]);
    return 0;
}
