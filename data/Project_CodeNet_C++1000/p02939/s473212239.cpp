#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	long long cnt;
	int len;

	cin >> s;
	cnt = 0;
	rep(i, s.size())
	{
		len = 1;
		while(s.substr(i, len) == t && i + len < s.size())
		{
			len++;
		}
		if (t != s.substr(i, len))
			cnt++;
		t = s.substr(i, len);
		i += len - 1;
	}
	cout << cnt << endl;
	return 0;
}
