#include <bits/stdc++.h>
#define reg register
inline int read()
{
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
using namespace std;
const int maxn = 505;
int f[maxn], g[maxn];
int a[maxn][maxn];

void get(int l, int r) {
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
    int n = read();
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
    get(1, n);
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++)
            printf("%d ", a[i][j]);
        puts("");
    }
}