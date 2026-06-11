#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n, m, x;
	cin >> n >> m >> x;
	
	int c[n];
	int grid[n][m];
	
	for(int i = 0; i<n; i++)
	{
		cin >> c[i];
		for(int j = 0; j<m; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	int ans = INT_MAX;
	for(int mask = 0; mask<1<<n; mask++)
	{
		int cost = 0;
		vector<int> temp(m);
		for(int i = 0; i<n; i++)
		{
			if(mask&(1<<i))
			{
				cost += c[i];
				for(int j = 0; j<m; j++)
				{
					temp[j] += grid[i][j];
				}
			}
		}
		int flag = 1;
		for(int s :temp)
		{
			if(s < x)
			{
				flag = 0;
				break;
			}
		}
		if(flag) ans = min(ans, cost);
		
	}
	if(ans == INT_MAX) cout << -1 << "\n";
	else cout << ans << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
