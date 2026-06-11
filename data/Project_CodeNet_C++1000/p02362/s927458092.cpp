#include <bits/stdc++.h>
using namespace std;
const int inf = 1012345678;
int V, E, s, a[2009], b[2009], c[2009], dist[2009];
int main() {
	scanf("%d%d%d", &V, &E, &s);
	for(int i = 0; i < E; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	fill(dist, dist + V, inf); dist[s] = 0;
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < E; j++) {
			dist[b[j]] = min(dist[b[j]], dist[a[j]] + c[j]);
		}
	}
	bool flag = false;
	for(int i = 0; i < E; i++) {
		if(dist[b[i]] < inf / 2 && dist[a[i]] + c[i] < dist[b[i]]) flag = true;
	}
	if(flag) puts("NEGATIVE CYCLE");
	else for(int i = 0; i < V; i++) {
		if(dist[i] >= inf / 2) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}