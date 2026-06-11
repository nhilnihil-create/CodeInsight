#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<P> rec(n - 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		rec[i] = P(a, b);
	}
	int ans1 = 0;
	rep(i, n) maxs(ans1, (int)g[i].size());
	vector<bool> used(n);
	map<P, int> mp;
	function<void(int, int)> Dfs = [&](int v, int prev) {
		used[v] = true;
		queue<int> que;
		rep(i, (int)g[v].size()) if (i + 1 != prev) que.push(i + 1);
		for (int c : g[v]) {
			if (used[c]) continue;
			mp[P(v, c)] = que.front();
			mp[P(c, v)] = que.front();
			Dfs(c, que.front());
			que.pop();
		}
	};
	rep(i, n) if (!used[i]) Dfs(i, -1);
	cout << ans1 << endl;
	rep(i, n - 1) cout << mp[rec[i]] << endl;
	return 0;
}
