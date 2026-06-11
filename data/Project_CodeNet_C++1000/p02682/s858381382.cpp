#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c, k; cin >> a >> b >> c >> k;
	if (k - a >= 0)
	{
		k = k - a;
		if (k - b >= 0)
		{
			k = k - b;
			if (k - c >= k)
			{
				cout << a - c << endl;
			}
			else
				cout << a - k << endl;
		}
		else
			cout << a << endl;
	}
	else
		cout << k << endl;
	return 0;
}