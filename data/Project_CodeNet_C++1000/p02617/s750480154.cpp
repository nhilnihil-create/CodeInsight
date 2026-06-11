#include <iostream>
#include <cstdio>

using namespace std;

int n;

int head[200010], to[400010], nxt[400010], cnt;

inline void AddEdge (int u, int v) { ++cnt, to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt; }

long long ans;

inline void Dfs (int u, int p) {
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == p) continue;
		if (v < u) ans += 1ll * v * (u - v);
		else ans += 1ll * (v - u) * (n - v + 1);
		Dfs (v, u);
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf ("%d%d", &u, &v);
		AddEdge (u, v), AddEdge (v, u);
	}
	
	Dfs (1, 0);
	
	printf ("%lld\n", ans + n);
	
	return 0;
}