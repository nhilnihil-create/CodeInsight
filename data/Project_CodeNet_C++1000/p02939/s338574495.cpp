#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

char s[200005];

int f[200005][5];

bool diff(int x, int y, int l)
{
    while (l) {
        if (s[x] != s[y]) return true;
        x--; y--; l--;
    }
    return false;
}

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(2, i); j++) {
            f[i][j] = -1000000000;
            for (int k = 1; k <= max(min(2, i-j), 1); k++) {
                if (i-j == 0 || j != k || diff(i, i-j, k)) {
                    f[i][j] = max(f[i][j], f[i-j][k] + 1);
                }
            }
            //debug("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }
    printf("%d", max(f[n][1], f[n][2]));
    return 0;
}
