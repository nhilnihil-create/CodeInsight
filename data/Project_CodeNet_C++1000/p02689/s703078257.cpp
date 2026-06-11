#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
int height[N];
int maxHeight[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &height[i]);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        maxHeight[u] = max(maxHeight[u], height[v]);
        maxHeight[v] = max(maxHeight[v], height[u]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (height[i] > maxHeight[i]) ++cnt;
    }
    printf("%d\n", cnt);
}