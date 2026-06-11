#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

signed main()
{
	string s;
	int k, l, ans = 0, tmp;

	cin >> s;
	cin >> k;

	l = s.length();

	tmp = 0;
	rep (i, l)
	{
		tmp++;
		if (i == l - 1 || s[i] != s[i + 1])
		{
			ans += tmp / 2;
			tmp = 0;
		}
	}

	ans *= k;

	if (s[0] == s[l - 1])
	{
		tmp = 1;
		rep (i, l - 1)
		{
			if (s[i] != s[i + 1]) break;
			tmp++;
		}
		if (tmp == l)
		{
			cout << l * k / 2 << endl;
			return 0;
		}
		if (tmp % 2)
		{
			tmp = 1;
			rep (i, l - 1)
			{
				if (s[l - 1 - i] != s[l - 2 - i]) break;
				tmp++;
			}
			if (tmp % 2) ans += k - 1;
		}
	}

	cout << ans << endl;
}
