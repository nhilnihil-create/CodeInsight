#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans;
	bool flag;
	string x;
	cin >> n;
	pair<string, int> p[n];

	rep(i, n) cin >> p[i].first >> p[i].second;
	cin >> x;
	ans = 0;
	flag = false;
	rep(i, n)
	{
		if (flag)
			ans += p[i].second;
		if (p[i].first == x)
			flag = true;
	}
	cout << ans << endl;
	return 0;
}
