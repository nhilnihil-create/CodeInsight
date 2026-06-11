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

int n;
vector<int> g[100005];
vector<int> ans(100005);
map<P, int> mp;
int ans1;

void dfs(int v, int p = -1, int prev = -1) {
	int pos = 0;
	int li = ans1;
	while (pos == prev || pos == li) pos++;
	for (int c : g[v]) {
		if (c == p) continue;
		mp[P(c, v)] = pos;
		mp[P(v, c)] = pos;
		dfs(c, v, pos);
		pos++;
		while (pos == prev || pos == li) pos++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<P> res(n - 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		res[i] = P(a, b);
	}
	ans1 = 0;
	rep(i, n) maxs(ans1, int(g[i].size()));
	printf("%d\n", ans1);
	dfs(0);
	rep(i, n - 1) {
		printf("%d\n", mp[res[i]] + 1);
	}
	return 0;
}
