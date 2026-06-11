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
vector<int> col, v;
vector<vector<int>> colrow;
int k, s;
int update(int x)
{
	while (x)
	{
		if (2 * x + 1 < k)
			v[x] = max(v[2 * x], v[2 * x + 1]);
		x /= 2;
	}
	return 0;
}
int count(int x, int lx, int rx, int l, int r)
{
	if (lx > r || rx < l)
	{
		return 0;
	}
	else if (lx >= l && lx <= r && rx >= l && rx <= r)
	{
		return v[x];
	}
	else
	{
		if (2 * x + 1 < k)
		{
			int mid = l + r; mid /= 2;
			int ans = max(count(2 * x, lx, mid, l, r), count(2 * x + 1, mid + 1, rx, l, r));
			return ans;
		}
		else
			return 0;
	}
}
int query(int l, int r)
{
	return count(1, 1, s + 1, l, r);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int h, w, m;
	cin >> h >> w >> m;
	colrow.resize(w + 1); col.resize(w + 1, 0);
	k = 0;
	for (; k < 30; k++)
	{
		if ((1 << k) >= h)
			break;
	}
	s = 1 << k; s--;
	k++; k = 1 << k;
	v.resize(k + 1, 0);
	while (m--)
	{
		int a, b;
		cin >> a >> b; col[b]++;
		v[s + a]++;
		colrow[b].pb(a);
		update(s + a);
	}
	int ans = 0;
	for (int i = 1; i <= w; i++)
	{
		for (int j = 0; j < colrow[i].size(); j++)
		{
			int a = colrow[i][j];
			v[s + a]--;
			update(s + a);
		}
		int ans1 = query(1, s + 1); ans1 += col[i];
		ans = max(ans, ans1);
		for (int j = 0; j < colrow[i].size(); j++)
		{
			int a = colrow[i][j];
			v[s + a]++;
			update(s + a);
		}


	}
	cout << ans << endl;
	return 0;
}

