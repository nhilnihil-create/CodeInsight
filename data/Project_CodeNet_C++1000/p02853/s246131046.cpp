#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int n, m, ans;
	int syokin[3];

	cin >> n >> m;
	syokin[2] = pow(10, 5);
	syokin[1] = 2 * syokin[2];
	syokin[0] = 3 * syokin[2];
	ans = 0;
	if (n == 1 && m == 1)
		cout << 10 * syokin[2] << endl;
	else
	{
		if (n - 1 < 3)
		ans += syokin[n - 1];
		if (m - 1 < 3)
		ans += syokin[m - 1];
		cout << ans << endl;
	}
	return 0;
}
