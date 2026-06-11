#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

vector<int>E[100000];
int d[100000], pr[100000];

void rec(int v, int p) {
	d[v] = p;
	for (int u : E[v])rec(u, p + 1);
}
int main() {
	int n; scanf("%d", &n);
	memset(pr, -1, sizeof(pr));
	rep(i, n) {
		int id, k; scanf("%d%d", &id, &k);
		rep(j, k) {
			int c; scanf("%d", &c);
			E[id].push_back(c);
			pr[c] = id;
		}
	}
	rep(i, n) {
		if (!~pr[i]) {
			rec(i, 0); break;
		}
	}
	rep(i, n) {
		printf("node %d: parent = %d, depth = %d, ", i, pr[i], d[i]);
		if (!~pr[i])printf("root, [");
		else if (E[i].empty())printf("leaf, [");
		else printf("internal node, [");
		rep(j, E[i].size()) {
			if (j)printf(", ");
			printf("%d", E[i][j]);
		}
		printf("]\n");
	}
}