#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n, d;
	cin >> n >> d;
	int x, y;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		long long distance = (long long)x * x + (long long)y * y;
		if (distance <= (long long)d * d) ans++;
	}
	cout << ans << endl;
	return (0);
}
