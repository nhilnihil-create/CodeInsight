#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, k;
	long long ans;
	string s, t;

	cin >> n >> k >> s;
	ans = 0;
	rep(i, n - 1)
	{
		if (s[i] == s[i + 1])
			ans++;
	}
	ans = min((int)ans + 2 * k, n - 1);
	cout << ans << endl;
	return 0;
}
