#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> cnt(n + 1);

	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int m;
			cin >> m;
			cnt[m]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) if (cnt[i] == 0) ans++;
	cout << ans;
}
