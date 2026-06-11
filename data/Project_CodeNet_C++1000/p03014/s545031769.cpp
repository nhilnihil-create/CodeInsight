#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e3 + 5;

int n, m;
char c[N][N];
int a[N][N], l[N][N], u[N][N], r[N][N], d[N][N];


int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if(c[i][j] == '.')
				a[i][j] = 1;
		}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!a[i][j])
				l[i][j] = 0;
			else
				l[i][j] = 1 + l[i][j - 1];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 1; j--)
		{
			if(!a[i][j])
				r[i][j] = 0;
			else
				r[i][j] = 1 + r[i][j + 1];
		}
	}
	for(int j = 1; j <= m; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(!a[i][j])
				u[i][j] = 0;
			else
				u[i][j] = 1 + u[i - 1][j];
		}
	}
	for(int j = 1; j <= m; j++)
	{
		for(int i = n; i >= 1; i--)
		{
			if(!a[i][j])
				d[i][j] = 0;
			else
				d[i][j] = 1 + d[i + 1][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j])
			{
				ans = max(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
			}
		}
	}
	cout << ans;
	return 0;
}
