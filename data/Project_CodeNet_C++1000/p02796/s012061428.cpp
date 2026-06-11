#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans, s;
	cin >> n;
	vector<pair<int, int>> r(n), p(n);

	rep(i, n) cin >> r[i].first >> r[i].second;
	rep(i, n)
		p[i] = make_pair(r[i].first + r[i].second, r[i].first - r[i].second);
	sort(p.begin(), p.end());
	ans = 1;
	s = p[0].first;
	for(int i = 1; i < n; i++)
	{
		if (s <= p[i].second)
		{
			ans++;
			s = p[i].first;
		}

	}
	cout << ans << endl;
	return 0;
}
