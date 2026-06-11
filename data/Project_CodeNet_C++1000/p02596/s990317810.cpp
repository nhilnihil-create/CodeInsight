#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int k;
	cin >> k;
	long long all = 0;
	for (int i = 0; i < k; i++)
	{
		all *= 10;
		all %= k;
		all += 7;
		all %= k;
		if (all == 0)
		{
			cout << i + 1 << endl;
			return (0);
		}
	}
	cout << -1 << endl;
	return (0);
}
