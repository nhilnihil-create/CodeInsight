#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

using Graph = vector<vector<int>>;
vector <ll> cnt;
vector <ll> sum;

void dfs(const Graph& graph, int v, int p, int val) {
	sum[v] = cnt[v] + val;
	for (auto nv : graph[v]){
		if (nv == p) continue;
		dfs(graph, nv, v, sum[v]);
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;

	Graph graph(N);
	for (int ii = 0; ii < N-1; ++ii){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cnt.assign(N, 0);
	for (int ii = 0; ii < Q; ++ii){
		int p, x;
		cin >> p >> x;
		p--;
		cnt[p] += x;
	}

	sum.assign(N, 0);
	int root = 0;
	dfs(graph, /*v=*/root, /*p=*/-1, 0);

	for (int ii = 0; ii < N; ++ii){
		printf("%i ", sum[ii]);
	}
	printf("\n");

	return 0;
}
