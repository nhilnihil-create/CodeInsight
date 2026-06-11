#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
int mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(3 * n);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[3 * u].push_back(3 * v + 1);
		g[3 * u + 1].push_back(3 * v + 2);
		g[3 * u + 2].push_back(3 * v);
	}
	int s, t;
	cin >> s >> t;
	s--, t--;
	queue<pair<int, int>> q;
	q.push({3 * s, 0});
	vector<int> visited(3 * n);
	while (!q.empty())
	{
		auto now = q.front();
		for (auto nxt : g[now.first])
		{
			if (!visited[nxt])
			{
				q.push({nxt, now.second + 1});
				visited[nxt] = now.second + 1;
			}
		}
		q.pop();
	}
	if (visited[3 * t])
	{
		cout << visited[3 * t] / 3 << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}