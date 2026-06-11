#include <bits/stdc++.h>
using namespace std;

#define N 10005

int n, m, cnt[N];

vector<int> to[N];

signed main(void)
{
	cin >> n >> m;
	
	memset(cnt, 0, sizeof(cnt));
	
	for (int u, v; m--; )
	{
		cin >> u >> v;
		to[u].push_back(v); ++cnt[v];
	}
	
	queue<int> que;
	
	for (int i = 0; i < n; ++i)
		if (!cnt[i])que.push(i);
		
	while (!que.empty())
	{
		int u = que.front(); que.pop();
		
		cout << u << endl;
		
		for (auto v : to[u])
			if (--cnt[v] == 0)
				que.push(v);
	}
}