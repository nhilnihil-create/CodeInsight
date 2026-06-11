#include <bits/stdc++.h>

using namespace std;

class DSU {
private:
	int n;
	vector<int> parent;
	vector<int> rank;

public:
	DSU(int n) : n(n) {
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
		rank.resize(n+1, 0);
	}
	
	int find(int a) {
		if (parent[a] != a)
			parent[a] = find(parent[a]);
		return parent[a];
	}
	
	bool merge(int a, int b) {
		int ap = find(a);
		int bp = find(b);
		if (ap == bp)
			return true;
		
		if (rank[ap] < rank[bp]) {
			parent[ap] = bp;
		} else if (rank[ap] > rank[bp]) {
			parent[bp] = ap;
		} else {
			parent[bp] = ap;
			rank[ap]++;
		}
		return false;
	}
};

int main() {
	int n, m, ans = 0;
	unordered_map<int, int> count;
	
	cin >> n >> m;
	DSU dsu(n+1);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dsu.merge(u, v);
	}
	
	for (int i = 1; i <= n; i++) {
		count[dsu.find(i)]++;
	}
	
	for (auto& e : count) {
		ans = max(ans, e.second);
	}
	
	cout << ans;
	return 0;
}

