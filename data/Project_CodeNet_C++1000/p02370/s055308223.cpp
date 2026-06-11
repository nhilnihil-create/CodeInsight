#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
const int maxx = 100010;
const int INF = 1 << 30;

vector<int>G[maxx];
list<int>out;
bool flag[maxx];
int n;

void dfs(int u) {
	flag[u] = true;

	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (flag[v] == 0)
			dfs(v);
	}
	out.push_front(u);
}

void tsort() {
	for (int i = 0; i < n; i++) {
		flag[i] = false;
	}

	for (int u = 0; u < n; u++) {
		if ( flag[u] == 0)
			dfs(u);
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++)
		printf("%d\n", *it);
}
int main()
{
	int s, t, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &t);
		G[s].push_back(t);
	}

	tsort();
	return 0;
}