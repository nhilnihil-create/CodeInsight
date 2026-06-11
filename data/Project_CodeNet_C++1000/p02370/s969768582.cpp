#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Mod (int)1000000007
#define INFTY (int)INT_MAX
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(S, s) S.find(s) != string::npos

vector<int> topological_sort(vector<vector<int>> &graph, vector<int> &indegree, int V) {
	vector<int> ans;
	queue<int> Q;
	Rep(i, V) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		Rep(i, graph[v].size()) {
			int u = graph[v][i];
			indegree[u]--;
			if (indegree[u] == 0) Q.push(u);
		}
		ans.push_back(v);
	}
	return ans;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>> graph(V);
	vector<int> indegree(V);
	Rep(i, E) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	vector<int> ans = topological_sort(graph, indegree, V);
	Rep(i, V) {
		cout << ans[i] << endl;
	}
	return 0;
}
