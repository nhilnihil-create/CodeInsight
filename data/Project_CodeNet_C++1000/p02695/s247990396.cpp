#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[55], b[55], c[55], d[55];

long long mx = 0;

void dfs(vector<int> v)
{
	if (v.size() == n + 1)
	{
		long long cnt = 0;
		for (int i = 0; i < q; i++)
		{
			if (v[b[i]] - v[a[i]] == c[i]) cnt += d[i];
		}
		mx = max(mx, cnt);
		return ;
	}
	for (int i = v[v.size() - 1]; i <= m; i++)
	{
		v.push_back(i);
		dfs(v);
		v.erase(v.begin() + v.size() - 1);
	}
	return ;
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> vv;
	vv.push_back(1);
	dfs(vv);
	cout << mx << endl;
	return 0;
}