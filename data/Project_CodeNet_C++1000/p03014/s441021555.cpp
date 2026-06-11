#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int h, w;
	cin >> h >> w;
	string s[h];
	int l[h][w], r[h][w], d[h][w], u[h][w];
	int L[h][w];
	rep(i, h) cin >> s[i];
	rep(i, h) rep(j, w + 1) l[i][j] = r[i][j] = 0;
	rep(i, h + 1) rep(j, w)	d[i][j] = u[i][j] = 0;
	rep(i, h) rep(j, w)
	{
		if (j == 0 && s[i][j] == '.')
			l[i][j] = 1;
		else if (s[i][j] == '.')
			l[i][j] += l[i][j - 1] + 1;
	}
	rep(i, h) for(int j = w - 1; j >= 0; j--)
	{
		if (j == w - 1 && s[i][j] == '.')
			r[i][j] = 1;
		else if (s[i][j] == '.')
			r[i][j] += r[i][j + 1] + 1;
	}
	rep(j, w) rep(i, h) 
	{
		if (i == 0 && s[i][j] == '.')
			d[i][j] = 1;
		else if (s[i][j] == '.')
			d[i][j] += d[i - 1][j] + 1;
	}
	rep(j, w) for(int i = h - 1; i >= 0; i--)
	{
		if (i == h - 1 && s[i][j] == '.')
			u[i][j] = 1;
		else if (s[i][j] == '.')
			u[i][j] += u[i + 1][j] + 1;
	}
	int ans = 0;
	rep(i, h) rep(j, w)
	{
		L[i][j] = l[i][j] + r[i][j] + d[i][j] + u[i][j] - 3;
		ans = max(ans, L[i][j]);
	}
	cout << ans << endl;
	return 0;
}
