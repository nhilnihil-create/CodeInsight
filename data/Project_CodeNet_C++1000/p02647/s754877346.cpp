#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	while (k--) {
		bool flag = true;
		vector<int> c(n + 1, 0);
		for (int i = 0; i < n; i++) {
			if (a[i] != n) flag = false;
			int l = max(0, i - a[i]), r = min(i + a[i], n - 1);
			c[l]++; c[r + 1]--;
		}
		if (flag) break;
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += c[i];
			a[i] = s;
		}
	}
	for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
	return 0;
}
