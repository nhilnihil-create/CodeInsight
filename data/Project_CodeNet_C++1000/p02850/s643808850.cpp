#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007

Graph g;
vector<Pair> edge;
map <Pair, int> col;

void	dfs(int node, int color)
{
	int c = 1;
	for (auto it = g[node].begin(); it != g[node].end(); it++)
	{
		if (c == color)
			c++;
		Pair e;
		if (*it < node)
			e = make_pair(*it, node);
		else
			e = make_pair(node, *it);
		if(col.find(e) != col.end())
			continue ;
		col.insert(make_pair(e, c));
		dfs(*it, c);
		c++;
	}
}

int		main(void)
{
	int n;
	cin >> n;
	g = Graph(n);
	edge = vector<Pair>(n-1);
	for (auto it = edge.begin(); it != edge.end(); it++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		it->first = a;
		it->second = b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int num_edge = g[i].size();
		if (num_edge > max)
			max = num_edge;
	}
	dfs(0, 0);
	cout << max << endl;
	for (auto it = edge.begin(); it != edge.end(); it++)
	{
		Pair e;
		if (it->first < it->second)
			e = make_pair(it->first, it->second);
		else
			e = make_pair(it->second, it->first);
		cout << col.at(e) << endl;
	}
}
