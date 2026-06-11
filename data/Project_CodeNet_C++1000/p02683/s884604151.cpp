#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
const int INF = 1e9 + 7;

int n, m, x;
vector<vector<int>> a(N, vector<int>(N));
vector<int> c(N);

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int ans = INF;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		vector<int> temp(m);
		int cost = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) & 1)
			{
				cost += c[i];
				for (int j = 0; j < m; j++)
					temp[j] += a[i][j];
			}
		}
		bool ok = true;
		for (int j = 0; j < m; j++)
			if (temp[j] < x)
				ok = false;
		if (ok)
			ans = min(ans, cost);
	}
	if (ans != INF)
		cout << ans;
	else
		cout << -1;
	return 0;
}
//11-09-2020 17:10:06