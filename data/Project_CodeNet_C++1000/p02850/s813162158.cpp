#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
struct Edge {
	int to;
	int id;
};
vector<vector<Edge>> g;
vector<int> ans;
void dfs(int p, int c = -1, int q = -1) {
	int k = 1;
	for (int i = 0; i < g[p].size(); ++i) {
		int np = g[p][i].to; int nid = g[p][i].id;
		if (c == k) k++;
		if (np == q) continue;
		ans[nid] = k++;
		dfs(np, ans[nid], p);
	}
	return;
}

void solve() {
	int n; cin >> n;
	g.resize(n);
	ans = vector<int>(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	dfs(0);
	int  color = 0;
	for (int i = 0; i < ans.size(); ++i) {
		color = max(color, ans[i]);
	}
	cout << color << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}