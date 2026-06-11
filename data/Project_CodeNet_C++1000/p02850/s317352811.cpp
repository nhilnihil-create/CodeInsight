#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;


struct Edge {
	int to, id;
};

using Graph = vector<vector<Edge>>;

int degree;
vector <int> edgeColor;

void dfs(const Graph& graph, int v, int p, int pcolor) {
	int color = 1;
	for (auto tmp : graph[v]){
		int nv = tmp.to;
		int idx = tmp.id;
		if (nv == p) continue;
		if (color == pcolor){
			color++;
		}
		edgeColor[idx] = color;
		dfs(graph, nv, v, color);
		color++;
	}
}

int main() {
	//木の構造を与える
	int N;
	cin >> N;

	Graph graph(N);
	for (int ii = 0; ii < N-1; ++ii){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		Edge e1, e2;
		e1.to = b; e1.id = ii;
		e2.to = a; e2.id = ii;
		graph[a].push_back(e1);
		graph[b].push_back(e2);
	}

	//最大次数を求める
	degree = 0;
	for (int ii = 0; ii < N-1; ++ii){
		degree = max(degree, (int)graph[ii].size());
	}

	//初期化
	edgeColor.assign(N-1, 0);

	int root = 0;
	dfs(graph, /*v=*/root, /*p=*/-1, /*pcolor=*/0);

	cout << degree << endl;
	for (int ii = 0; ii < N-1; ++ii){
		cout << edgeColor[ii] << endl;
	}

	return 0;
}
