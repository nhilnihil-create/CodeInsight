#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100010 ;
int n, m;
int in[MAXN];
bool vis[MAXN];
vector<int> edge[MAXN];
queue<int> q;
int main()
{
	memset(vis, false, sizeof(vis));
	cin >> n >> m;
	for (int i = 1, s, t; i <= m; ++i)
	{
		cin >> s >> t;
		edge[s].push_back(t);
		in[t] ++;
	}
	for (int i = 0; i < n; ++i)
		if (in[i] == 0 && ! vis[i])
		{
			vis[i] = true;
			q.push(i);
		}
	while (! q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << endl;
		for (int i = 0; i < edge[cur].size(); ++i)
		{
			int v = edge[cur][i];
			in[v] -- ;
			if (in[v] == 0 && ! vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return 0;
}

