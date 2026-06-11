#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define umap unordered_map
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printVerdict(verdict) cout << (verdict ? "Yes": "No") << '\n'
#define printDecimal(d) printf("%.9f\n", d)
#define inrange(val, start, end) (val >= start && val <= end)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const ll inf = 0x3f3f3f3f;

template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
void printPair(pair<T1, T2> p) { cout << p.first << " " << p.second << '\n'; }
template <class T>
void printArray(vector<T> arr) { for (int i = 0; i<size(arr); i++) {cout << arr[i] << " ";} cout << '\n'; }

void dfs(int curr, vector<vector<int>> &graph, vector<bool> &visited) {
	visited[curr] = true;
	for (int neighbor : graph[curr]) {
		if (!visited[neighbor]) dfs(neighbor, graph, visited);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	vector<bool> visited(n+1,false);
	vector<vector<int>> graph(n+1, vector<int>());
	for (int i = 0; i<m; i++) {
		int u,v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int comp_cnt = 0;
	for (int i = 1; i<=n; i++) {
		if (!visited[i]) {
			dfs(i, graph, visited);
			comp_cnt++;
		} 
	}
	cout << comp_cnt - 1 << '\n';
}

