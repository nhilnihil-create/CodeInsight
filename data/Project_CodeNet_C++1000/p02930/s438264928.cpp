#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 505;
int f[maxn], g[maxn];
int a[maxn][maxn];

void get(int l, int r) {
    /* debug("get %d %d\n", l, r); */
    int n = r - l + 1;
    if(n <= 2) {
        a[l][r] = f[n];
        return;
    }
    int mid = l + g[n] - 1;
    get(l, mid);
    get(mid + 1, r);
    for(int i = l; i <= mid; i ++)
        for(int j = mid + 1; j <= r; j ++)
            a[i][j] = f[n];
}

int main() {
    int n = input();
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i ++) {
        f[i] = 1000000000;
        for(int j = 1; j < i; j ++) {
            int v = std::max(f[j], f[i - j]) + 1;
            if(v < f[i]) {
                f[i] = v;
                g[i] = j;
            }
        }
    }

    /* for(int i = 1; i <= n; i ++) */
    /*  debug("%d %d\n", f[i], g[i]); */

    get(1, n);
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++)
            printf("%d ", a[i][j]);
        puts("");
    }
}
