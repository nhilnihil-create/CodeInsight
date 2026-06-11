#include <bits/stdc++.h>
using namespace std;

vector<int> present(200001, 1);

int getSize(int person, vector<vector<int>>& graph)
{
	if(!present[person]) return 0;
	int ret = 1;
	present[person] = 0;

	for(auto& node: graph[person])
	{
		ret += getSize(node, graph);
	}
	return ret;
}

int main()
{
	int n, m; cin >> n >> m;
	int a, b;
	vector<vector<int>> graph(n+1);
	for(int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		present[a] = present[b] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(present[i])
		{
			ans = max(ans, getSize(i, graph));
		}
	}

	cout << ans;

	return 0;
}