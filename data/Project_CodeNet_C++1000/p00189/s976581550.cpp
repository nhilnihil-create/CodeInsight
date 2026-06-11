#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, a, b, c, s;
int g[11][11];
int main() {
    while ((~scanf("%d", &n)) && n) {
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < 11; ++j)
                if (i == j) g[i][i] = 0;
                else g[i][j] = 1000000;
        s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            //printf("%d %d %d\n", a, b, c);
            g[a][b] = c;
            g[b][a] = c;
            s = max(s, max(a, b));
        }
        for (int k = 0; k <= s; ++k)
            for (int i = 0; i <= s; ++i)
                for (int j = 0; j <= s; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        int ans = 10000000, id = -1;
        for (int i = 0; i <= s; ++i) {
            int t = 0;
            for (int j = 0; j <= s; ++j) t += g[i][j];
            if (ans > t) {
                id = i;
                ans = t;
            }
        }
        printf("%d %d\n", id, ans);
    }
    return 0;
}

