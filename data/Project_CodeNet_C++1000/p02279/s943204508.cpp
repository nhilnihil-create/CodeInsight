#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> et[100000];
int root_id;
int parent[100000];
int depth[100000];

void input() {
	static bool is_root[100000];
	
	cin >> n;
	for (int i = 0; i < n; i++) is_root[i] = true;
		
	for (int i = 0; i < n; i++) {
		int id, k, ch_id;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> ch_id;
			et[id].push_back(ch_id);
			is_root[ch_id] = false;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (is_root[i]) {
			root_id = i;
			break;
		}
	}
}

void dfs(int p, int v, int dep = 0) {
	parent[v] = p;
	depth[v] = dep;
	for (int i = 0; i < et[v].size(); i++) {
		dfs(v, et[v][i], dep + 1);
	}
}

int main() {
	input();
	dfs(-1, root_id);
	
	for (int i = 0; i < n; i++) {
		char *type;
		if (i == root_id) type = "root";
		else if (et[i].size() == 0) type = "leaf";
		else type = "internal node";
		printf("node %d: parent = %d, depth = %d, %s, [", i, parent[i], depth[i], type);
		for (int j = 0; j < et[i].size(); j++) {
			printf("%d", et[i][j]);
			if (j + 1 < et[i].size()) printf(", ");
		}
		printf("]\n");
	}
	return 0;
}