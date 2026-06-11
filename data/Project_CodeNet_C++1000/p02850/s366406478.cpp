#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	vector<vector<int>> G(n);
	vector<pair<int, int>> p;
	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		p.push_back(make_pair(a, b));
	}
	int K=0;
	map<pair<int, int>, int> I;
	vector<int> C(n, 0);
	queue<int> que;

	vector<int> visit(n, 0);
	visit[0] = 1;
	que.push(0);
	while(!que.empty()) {
		int now = que.front();
		que.pop();
		if (K < G[now].size()) K = G[now].size();
		int cl = 1;
		for (int u:G[now]) {
			if (visit[u]) continue;
			if (cl == C[now]) cl++;
			C[u] = I[make_pair(u, now)] = I[make_pair(now,u)] = cl++;
			visit[u] = 1;
			que.push(u);
		}
	}
	cout << K << endl;
	for (auto x:p) cout << I[x] << endl;
	return 0;
}