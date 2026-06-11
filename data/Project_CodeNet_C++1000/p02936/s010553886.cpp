#include "bits/stdc++.h"
using namespace std;
int N;
vector<int>to[200005];
vector<int> ans;
void dfs(int v, int p = -1) {
	for (int e : to[v]) {
		if (p == e) {
			continue;
		}
		ans[e] += ans[v];
		dfs(e, v);
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	for (int n = 0; n < N - 1; ++n) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}	
	ans.resize(N);
	for (int n = 0; n < Q; ++n) {
		int p, q;
		cin >> p >> q;
		p--;
		ans[p] += q;
	}	
	dfs(0);
	for (int n = 0; n < N ; ++n) {
		cout << ans[n] << endl;
	}
	return 0;
}
