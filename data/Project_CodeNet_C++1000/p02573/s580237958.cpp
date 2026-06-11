#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 10;
const int M = 2 * 1e5 + 10;
int n, m, maxn;
int s[N], f[N], fa[N];

int get_fa (int x) {
	if (fa[x] == x) return x;
	else return fa[x] = get_fa (fa[x]);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) {
		s[i] = 1;
		fa[i] = i;
	}
	for (int i = 1; i <= m; i ++ ) {
		int x, y, fx, fy;
		scanf ("%d%d", &x, &y);
		fx = get_fa (x);
		fy = get_fa (y);
		if (fx == fy) continue;
		else {
			fa[fx] = fy;
			s[fy] += s[fx];
			s[fx] = 0;
		}
	}
	for (int i = 1; i <= n; i ++ ) maxn = max (maxn, s[i]);
	printf ("%d\n", maxn);
	return 0;
}