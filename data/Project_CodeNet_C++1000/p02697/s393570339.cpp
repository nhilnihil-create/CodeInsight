#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, x, y, k;
signed main() {
    scanf ("%d %d", &n, &m);
    x = 1, y = 1 + m;
    if (m & 1) {
        for (int i = 1; i <= m / 2 + 1; ++i)
            printf ("%d %d\n", x, y), ++x, --y;
        x = 2 + m, y = x + m - 1;
        for (int i = 1; i <= m / 2; ++i)
            printf ("%d %d\n", x, y), ++x, --y;
    }
    else {
        for (int i = 1; i <= m / 2; ++i)
            printf ("%d %d\n", x, y), ++x, --y;
        x = 2 + m, y = x + m - 1;
        for (int i = 1; i <= m / 2; ++i)
            printf ("%d %d\n", x, y), ++x, --y;
    }
    return 0;
}
