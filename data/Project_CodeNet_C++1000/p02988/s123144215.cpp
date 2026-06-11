#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n], ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i - 1] < a[i]  && a[i] < a[i + 1])
		{
			ans++;
		}
		else if (a[i - 1] > a[i] && a[i] > a[i + 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
