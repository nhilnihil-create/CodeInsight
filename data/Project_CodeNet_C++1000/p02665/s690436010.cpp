#include "bits/stdc++.h"
using namespace std;

int64_t MAX = 1000000000000000;

int main()
{
	int n;

	cin >> n;
	vector<int64_t> a(n + 1);		// 葉
	vector<int64_t> mae(n + 1);		// 前から見た時の最大頂点数
	vector<int64_t> ushiro(n + 1);	// 後ろから見た時の最大頂点数
	for (int i = 0; i <= n; i++) {
		cin >> a.at(i);
	}

	if (n == 0) {
		if (a.at(0) == 1) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}

	mae.at(0) = 1;
	for (int i = 1; i <= n; i++) {
		mae.at(i) = min((mae.at(i - 1) - a.at(i - 1)) * 2, MAX);
		if (mae.at(i) < 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	ushiro.at(n) = a.at(n);
	for (int i = n - 1; i >= 0; i--) {
		ushiro.at(i) = min(ushiro.at(i + 1) + a.at(i), MAX);
	}

	int64_t ans = 0;
	for (int i = 0; i <= n; i++) {
		int64_t temp = min(mae.at(i), ushiro.at(i));
		if (temp < a.at(i)) {
			cout << -1 << endl;
			return 0;
		}
		ans += temp;
	}

	cout << ans << endl;
}
