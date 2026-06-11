#include<bits/stdc++.h>
using namespace std;

const int N = 200009;
int n, m, a[N], b[N], fa[N], Size[N], ans, cnt[N];

inline int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) fa[i] = i, Size[i] = 1;
//	for (int i = 1; i <= m; ++ i) scanf("%d", &a[i]);
//	for (int i = 1; i <= m; ++ i) scanf("%d", &b[i]);
//	for (int i = 1; i <= m; ++ i) {
//		int fx = get(a[i]), fy = get(b[i]);
//		if (fx == fy) continue;
//		fa[fx] = fy;
//		Size[fy] += Size[fx];
//	}
	while(m --) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = get(x), y = get(y);
		if (x != y) fa[y] = x, Size[x] += Size[y];
	}
//	for (int i = 1; i <= n; ++ i) {
//		int father = get(i);
//		++ cnt[father];
//		ans = max(ans, cnt[father]);
//	}
	for (int i = 1; i <= n; ++ i) if (get(i) == i) ans = max(ans, Size[i]);
	printf("%d\n", ans);
	return 0;
}