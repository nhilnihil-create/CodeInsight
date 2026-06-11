#include <bits/stdc++.h>
using namespace std;
const int N = 200001;

int s[N], f[N];
void init(int n) {
    fill_n(f + 1, n, 0);
    fill_n(s + 1, n, 1);
}

int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    f[y] = x; s[x] += s[y];
}

int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    init(n);
    for (int i = 1; i <= m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        unite(x, y);
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, s[i]);
    printf("%d\n", ans);
    return 0;
}