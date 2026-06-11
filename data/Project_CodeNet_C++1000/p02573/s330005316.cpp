#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 111;
const ll mod = 1e9 + 7;
int f[maxn];
int sizze[maxn];
int F(int x) { return f[x] == x ? x : f[x] = F(f[x]); }
void merge(int x, int y) {
    if(F(x)==F(y)) return;
    sizze[F(y)] += sizze[F(x)];
    f[F(x)] = F(y);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        sizze[i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v);
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
        maxx = max(maxx, sizze[F(i)]);
    }
    printf("%d\n", maxx);
    return 0;
}