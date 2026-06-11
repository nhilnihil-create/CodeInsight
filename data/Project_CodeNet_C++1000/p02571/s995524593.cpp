#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	int ans, cnt;
	cin >> s >> t;

	ans = 1e9;
	rep(i, s.size() - t.size() + 1)
	{
		cnt = 0;
		rep(j, t.size())
		{
			if (s[i + j] != t[j])
				cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
