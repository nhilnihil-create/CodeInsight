#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	string s;
	cin >> n >> m >> s;
	n++;

	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + (s[i] == '1');
	}

	vector<int> ans;
	bool ok = true;

	for (int i = n - 1; i;) {
		int L = 0, R = min(i, m) + 1;
		while (R - L > 1) {
			int mid = (L + R) / 2;
			int cnt = pref[i + 1 - mid] - pref[i - min(i, m)];
			(cnt ==  min(i, m) - mid + 1? R : L) = mid;
		}

		if (L) {
			ans.push_back(L);
			i -= L;
		} else {
			ok = false;
			break;
		}
	}

	if (!ok) {
		cout << "-1\n";
	} else {
		reverse(ans.begin(), ans.end());
		for (auto el : ans) {
			cout << el << ' ';
		}
	}
}