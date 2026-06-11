#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 200000
using namespace std;
typedef long long ll;
using P = pair<int, int>;

vector<int> G[MAX];
vector<ll> cnt(MAX, 0);
void dfs(int v, int p = -1)
{
	for (auto u : G[v])
	{
		if (u == p) continue;
		cnt[u] += cnt[v];
		dfs(u, v);
	}
}

signed main(void)
{
	int n, q;
	cin >> n >> q;
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, q)
	{
		int p, x;
		cin >> p >> x;
		p--;
		cnt[p] += x;
	}
	dfs(0);
	rep(i, n) printf("%lld%c", cnt[i], i==n-1?'\n':' ');
	return 0;
}
