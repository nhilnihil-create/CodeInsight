#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
vector<vector<int>> g(MAX_N);
vector<int> cnt(MAX_N, 0);
vector<int> ans(MAX_N, 0);
vector<bool> visited(MAX_N, false);

void dfs(int x) {
	visited[x] = true;
	ans[x] += cnt[x];
	for (int ind : g[x]) {
		if (!visited[ind]) {
			cnt[ind] += cnt[x];
			dfs(ind);
		}
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i=0;i<N-1;i++) {
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	for (int i=0;i<Q;i++) {
		int p, x;
		cin >> p >> x;
		cnt[p-1] += x;
	}

	dfs(0);

	for (int i=0;i<N;i++) {
		cout << ans[i];
		if (i != N-1) cout << " ";
		else cout << endl;
	}
}