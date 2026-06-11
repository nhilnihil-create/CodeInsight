#include <bits/stdc++.h>
using namespace std;

int n, e, t1, t2;
vector <int> v[100005];
bool vis[100005];
deque <int> order;

void dfs(int node) {
	vis[node] = 1;
	for (int i : v[node]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	order.push_front(node);
}

int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i);
	}
	while (!order.empty()) {
		t1 = order.front();
		cout << t1 << endl;
		order.pop_front();
	}
}

