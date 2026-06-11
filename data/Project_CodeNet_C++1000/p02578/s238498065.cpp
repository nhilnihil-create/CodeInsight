#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long step = 0;
	int max_height = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < max_height) step += max_height - a[i];
		else max_height = a[i];
	}
	cout << step << endl;
	return (0);
}
