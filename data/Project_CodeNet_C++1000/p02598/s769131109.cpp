#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ok = 1e9;
	int ng = 0;
	while (abs(ok - ng) > 1)
	{
		int mid = (ok + ng) / 2;
		int tmp_cnt = 0;
		for (int i = 0; i < n; i++) tmp_cnt += (a[i] - 1) / mid;
		if (tmp_cnt <= k) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	return (0);
}
