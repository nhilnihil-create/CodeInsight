#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];
	vector<long long> acc(n + 1, 0);
	for (int i = 0; i < n; i++) acc[i + 1] = a[i] + acc[i];
	vector<long long> bcc(m + 1, 0);
	for (int i = 0; i < m; i++) bcc[i + 1] = b[i] + bcc[i];
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (acc[i] > k) break ;
		int ok = 0;
		int ng = m + 1;
		while (abs(ok - ng) > 1)
		{
			int mid = (ok + ng) / 2;
			if (acc[i] + bcc[mid] <= k) ok = mid;
			else ng = mid;
		}
		ans = max(ans, i + ok);
	}
	cout << ans << endl;
	return (0);
}
