#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int h, n;
	cin >> h >> n;
	long long int ara[n];
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> ara[i];
		if (h >= 0)
		{
			h -= ara[i];
		}
	}
	if (h <= 0)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}