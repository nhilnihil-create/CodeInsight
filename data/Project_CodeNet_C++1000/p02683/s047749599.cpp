#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, x;
	cin >> n >> m >> x;
	std::vector<vector<int>> v(n, vector<int>(m + 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m + 1; ++j)
		{
			cin >> v[i][j];
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m + 1; ++j)
	// 	{
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int ans = INT_MAX;
	for (ll bit = 0; bit < (1 << n); ++bit)
	{
		std::vector<int> skill(m + 1, 0);
		int cost = 0;
		for (int i = 0; i < n; ++i)
		{
			if (bit & (1 << i))
			{
				cost = cost + v[i][0];
				for (int j = 1 ; j <= m; ++j)
				{
					skill[j] += v[i][j];
				}
			}
		}
		bool ck = true;
		for (int i = 1; i <= m ; ++i)
		{
			if (skill[i] < x)
			{
				ck = false;
				break;
			}
		}
		if (ck)
			ans = min (ans, cost);
	}
	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans << endl;
}