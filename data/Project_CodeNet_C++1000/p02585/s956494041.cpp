#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> c(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	vector<vector<long long>> a(n);
	vector<long long> cyc(n);
	for (int i = 0; i < n; i++) {
		a[i].emplace_back(0);
		long long sum = c[i];
		int next = p[i];
		while (next != i) {
			a[i].emplace_back(sum);
			sum += c[next];
			next = p[next];
		}
		cyc[i] = sum;
	}
	
	long long ans = -101010101010101010;
	for (int i = 0; i < n; i++) {
		if (cyc[i] > 0) {
			long long t = k / a[i].size() * cyc[i];
			ans = max(ans, t);
		} else {
			ans = max(ans, cyc[i]);
		}
		for (int j = 1; j <= min(k, (int)a[i].size() - 1); j++) {
			if (cyc[i] > 0) {
				long long t = (k - j) / a[i].size() * cyc[i] + a[i][j];
				ans = max(ans, t);
			} else {
				ans = max(ans, a[i][j]);
			}
		}
	}
	cout << ans << endl;

	return 0;
}