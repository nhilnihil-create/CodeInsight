#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "********************************************\n"
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL)
ll dp[200005][10][2], n, last, fun[10][10];
ll a[200005];
ll pwr(ll b, ll e)
{
	if (e < 0)
		return 1;
	ll ans = 1;
	while (e)
	{
		if (e & 1)
			ans = (ans * b);
		b = (b * b);
		e >>= 1;
	}
	return ans;
}
ll cal(ll idx, ll lv, ll f)
{
	if (idx == n)
		return (lv == last);
	if (dp[idx][lv][f] != -1)
		return dp[idx][lv][f];
	ll lim, ans = 0;
	if (f)
		lim = a[idx];
	else
		lim = 9;
	for (int i = 0; i <= lim; ++i)
	{
		if (f)
		{
			if (i < lim)
				ans += cal(idx + 1, i, 0);
			else
				ans += cal(idx + 1, i, 1);
		}
		else
		{
			ans += cal(idx +  1, i, 0);
		}
	}
	return dp[idx][lv][f] = ans;
}
ll solve()
{
	memset(dp, -1, sizeof(dp));
	return cal(1, a[0], 1);
}
int main(int argc, char const *argv[])
{
	fast;
	string s;
	cin >> s;
	n = s.length();
	for (int i = 0; i < s.length(); ++i)
	{
		a[i] = s[i] - '0';
	}
	if (n == 1)
		cout << s;
	else
	{
		
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 0; j <= 9; ++j)
			{
				if (i < a[0])
					fun[i][j] = pwr(10, n - 2);
				else if (i == a[0])
				{
					last = j;
					fun[i][j] = solve();
				}
				for (int l = 2; l < n; ++l)
				{
					fun[i][j] += pwr(10, l - 2);
				}
				if (i == j)
					fun[i][j] ++;
			}
		}
		// for (int i = 0; i <= 9; ++i)
		// {
		// 	for (int j = 0; j <= 9; ++j)
		// 	{
		// 		cout << fun[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		ll ans = 0;
		for (int i = 0; i <= 9; ++i)
		{
			for (int j = 0; j <= 9; ++j)
			{
				ans += fun[i][j] * fun[j][i];
			}
		}
		cout << ans;
	}
	return 0;
}