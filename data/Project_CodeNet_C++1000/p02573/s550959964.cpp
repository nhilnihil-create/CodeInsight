#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int n, m;
vvi adj(200001);
vector<bool> visited(200001);

int dfs(int src)
{
	if (visited[src])
		return 0;
	visited[src] = true;
	int res = 1;
	for (int a : adj[src])
		res += dfs(a);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int maxcomp = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++)
	{
		int res = dfs(i);
		maxcomp = max(maxcomp, res);
	}
	cout << maxcomp << '\n';
}