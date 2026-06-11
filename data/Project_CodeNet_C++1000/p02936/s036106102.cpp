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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> rec(n);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		p--;
		rec[p] += x;
	}
	vector<int> ans(n);
	function<void(int, int, int)> Dfs = [&](int v, int p, int sum) {
		ans[v] = rec[v] + sum;
		sum += rec[v];
		for (int c : g[v]) {
			if (c == p) continue;
			Dfs(c, v, sum);
		}
	};
	Dfs(0, -1, 0);
	rep(i, n) cout << ans[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}