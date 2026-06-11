#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	long long k, ans, cnt;
	bool flag;

	cin >> s >> k;
	flag = true;
	rep(i, s.size() - 1)
	{
		if (s[i] != s[i + 1])
			flag = false;
	}
	if (flag)
		ans = s.size() * k / 2;
	else
	{
		ans = 0;
		if (s[0] != s[s.size() - 1])
		{
			rep(i, s.size() - 1)
			{
				if (s[i] == s[i + 1])
				{
					s[i + 1] = '*';
					ans++;
				}
			}
			ans *= k;
		}
		else
		{
			t = s + s;
			cnt = 0;
			rep(i, t.size() - 1)
			{
				if (t[i] == t[i + 1])
				{
					t[i + 1] = '*';
				}
			}
			rep(i, s.size())
			{
				if (s[0] == s[i])
					cnt++;
				else
					break;
			}
			for(int i = s.size(); i < t.size(); i++)
			{
				if (t[i] == '*')
					ans++;
			}
			if (t[s.size()] == '*' && cnt % 2 != 0) flag = true;
			ans *= k;
			if (flag) ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
