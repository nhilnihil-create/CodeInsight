#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n) {
		vector<int> a(n), sum(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum[i + 1] = sum[i] + a[i];
		}
		int res = -1000000000;
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				res = max(res, sum[j] - sum[i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}