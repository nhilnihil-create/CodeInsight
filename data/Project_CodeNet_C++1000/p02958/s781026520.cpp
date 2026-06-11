#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n], answer = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] != i + 1)
		{
			answer++;
		}
	}
	if (answer == 0 || answer == 2)
	{
		cout << "YES" << endl;
		/* code */
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}