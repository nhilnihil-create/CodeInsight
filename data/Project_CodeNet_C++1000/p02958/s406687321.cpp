#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i])
		{
			ans++;
		}
		if (ans > 2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	if (ans == 0 || ans == 2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}