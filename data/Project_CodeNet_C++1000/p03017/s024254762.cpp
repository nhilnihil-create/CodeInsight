#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, a, b, c, d;
	string s;
	bool ok;

	cin >> n >> a >> b >> c >> d >> s;
	a--; b--; c--; d--;
	ok = true;
	for(int i = a; i <= max(c, d); i++)
	{
		if (s.substr(i, 2) == "##")
			ok = false;
	}
	if (c > d)
	{
		ok = false;
		for(int i = b - 1; i < d; i++)
		{
			if (s.substr(i, 3) == "...")
			{
				ok = true;
				break;
			}
		}
	}
	if(ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
