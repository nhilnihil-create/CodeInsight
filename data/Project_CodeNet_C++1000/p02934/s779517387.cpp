#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	long double ans = 0;
	int a;
	while (n--)
	{
		cin >> a;
		ans += 1.0 / a;
	}
	ans = 1.0 / ans;
	cout << setprecision(16) << ans << endl;
	return 0;
}