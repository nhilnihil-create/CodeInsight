
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	ll h, w;
	cin >> h >> w;
	ll a[h + 2][w + 2] , l[h + 2][w + 2]  , u[h + 2][w + 2] , r[h + 2][w + 2] , d[h + 2][w + 2] ;
	for (ll i = 0; i <= h + 1; i++)
	{
		for (ll j = 0; j <= w + 1; j++)
		{
			a[i][j] = 0;
			l[i][j] = 0;
			u[i][j] = 0;
			r[i][j] = 0;
			d[i][j] = 0;
		}
	}
	for (ll i = 1; i <= h; i++)
	{
		string s;
		cin >> s;
		for (ll j = 1; j <= w; j++)
		{
			if (s[j - 1] == '.')
			{
				l[i][j] = l[i][j - 1] + 1;
				u[i][j] = u[i - 1][j] + 1;
			}
			else
				a[i][j] = 1;
		}
	}
	for (ll i = h; i >= 1; i--)
	{
		for (ll j = w; j >= 1; j--)
		{
			if (a[i][j] == 0)
			{
				r[i][j] = r[i][j + 1] + 1;
				d[i][j] = d[i + 1][j] + 1;
			}
		}
	}
	ll ans = 0, mx = 0;
	for (ll i = 1; i <= h; i++)
	{
		for (ll j = 1; j <= w; j++)
		{
			ans = 0;
			if (!a[i][j])
			{
				ans = l[i][j - 1] + r[i][j + 1] + u[i - 1][j] + d[i + 1][j] + 1;
			}
			mx = max(mx, ans);

		}
	}
	cout << mx << endl;
}