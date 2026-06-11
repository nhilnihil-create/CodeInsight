#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;

bool visit(const vector<vi>& g, int v, vector<int>& order, vector<int>& color) {
	color[v] = 1;
	for (int u : g[v]) {
		if (color[u] == 2) continue;
		if (color[u] == 1) return false;
		if (!visit(g, u, order, color)) return false;
	}
	order.push_back(v); color[v] = 2;
	return true;
}

// ?????????????????????????????????
// ???????????? true ???????????????????????????(false ?????´????????????)
bool TopologicalSort(const vector<vi>& g, vector<int>& order) {
	int n = g.size();
	vector<int> color(n);
	for (int u = 0; u < n; u++) if (!color[u] && !visit(g, u, order, color)) return false;
	reverse(order.begin(), order.end());
	return true;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vvi edge(V);
	rep(i, 0, E)
	{
		int s, t;
		cin >> s >> t;
		edge[s].push_back(t);
	}

	vi order;
	if(!TopologicalSort(edge, order)) return 0;
	rep(i, 0, V) cout << order[i] << endl;
}