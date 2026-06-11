#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int n; 
	cin >> n;
	vector<int> g[n];
	vector<pair<int, int>> ans;
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		ans.push_back(make_pair(a, b));
	}
	rep(i, n) sort(g[i].begin(), g[i].end());
	queue<pair<int, int>> que;
	map<pair<int, int>, int> mp;
	int pre = -1;
	int cnt, k;

	que.push(make_pair(0, pre));
	cnt = k = 0;
	while(!que.empty())
	{
		auto now = que.front();
		que.pop();
		cnt = 1;
		for(int u : g[now.first])
		{
			if (now.second == cnt)
				cnt++;
			mp[make_pair(now.first, u)] = cnt;
			pre = cnt;
			k = max(k, cnt);
			que.push(make_pair(u, pre));
			cnt++;
		}
	}
	cout << k << endl;	
	for(auto p : ans) cout << mp[p] << endl;
	return 0;
}
