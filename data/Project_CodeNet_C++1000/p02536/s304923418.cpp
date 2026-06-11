#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535
vector<int> par;
int parent(int x)
{
	if (par[x] == x)
		return x;
	else
	{
		par[x] = parent(par[x]);
		return par[x];
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	par.resize(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		par[i] = i;
	}
	while (m--)
	{
		int a, b;
		cin >> a >> b; int x, y;
		x = parent(a);
		y = parent(b);
		if (x == y)
		{

		}
		else if (x > y)
		{
			par[x] = y;
		}
		else
		{
			par[y] = x;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (par[i] == i)
			ans++;
	}
	cout << ans - 1;

	return 0;
}
