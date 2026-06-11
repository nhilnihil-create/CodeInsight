#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int n;
int depth[MAX_N];
int parent[MAX_N];
vector<int> child[MAX_N];

void BFS() {
	int rt;
	for (int i = 0; i < n; i++) {
		if (parent[i] == -1) {
			rt = i;
		}
	}
	queue<int> q;
	q.push(rt);
	depth[rt] = 0;
	while (!q.empty()) {
		for (auto& c : child[q.front()]) {
			q.push(c);
			depth[c] = depth[parent[c]] + 1;
		}
		q.pop();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		parent[i] = -1;

	for (int i = 0, id, k; i < n; i++) {
		cin >> id >> k;
		for (int j = 0, c; j < k; j++) {
			cin >> c;
			child[id].push_back(c);
			parent[c] = id;
		}
	}

	BFS();

	for (int i = 0; i < n; i++) {
		cout << "node " << i << ':';
		cout << " parent = " << parent[i] << ',';
		cout << " depth = " << depth[i] << ',';
		cout << (parent[i] == -1 ? " root" : (child[i].empty() ? " leaf" : " internal node")) << ',';
		if (child[i].empty()) {
			cout << " []";
		}
		else {
			cout << " [" << child[i][0];
			for (size_t j = 1; j < child[i].size(); j++) {
				cout << ", " << child[i][j];
			}
			cout << ']';
		}
		cout << endl;
	}
	return 0;
}