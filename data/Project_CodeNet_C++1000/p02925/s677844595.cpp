#include <bits/stdc++.h>
using namespace std;

int N;

int encode(int a, int b) {
	if(a > b) swap(a, b);
	return a * N + b;
}

int seen[1000000], dep[1000000];

int dfs(const vector<vector<int>> &edge, int now) {
	if(seen[now] == 2) return dep[now];
	seen[now] = 1;
	for(auto &e : edge[now]) {
		if(seen[e] == 1) {
			cout << -1 << endl;
			exit(0);
		}
		dep[now] = max(dep[now], dfs(edge, e) + 1);
	}
	seen[now] = 2;
	return dep[now];
}

int main() {
	cin >> N;
	vector<vector<int>> edge(N*N);
	for(int i=0;i<N;i++) {
		int now = 0;
		for(int j=0;j<N-1;j++) {
			int a;
			cin >> a;
			a--;
			int next = encode(i,a);
			edge[now].push_back(next);
			now = next;
		}
	}
	cout << dfs(edge, 0) << endl;
}