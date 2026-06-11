/*
─────────▄▄▄▄▄▄▄▄▄▄▄▄─────────
─────▄▄▀▀░░░░░░░░░░░░▀▀▄▄─────
───▄▀░░░░░░░░░░░░░░░░░░░░▀▄───
──█░░░░░▄▄▄▄▄░░░░▄▄▄▄▄░░░░░█──
─█░░░░░██░█░██▄▄██░█░██░░░░░█─
█░░░░░░░▀▀▀▀▀░░░░▀▀▀▀▀░░░░░░░█
█░░░░▄▄▄░░░░░░░░░░░░░░▄▄▄░░░░█
█░░░░██▀█▄▄▄▄▄▄▄▄▄▄▄▄██▀█░░░░█
─█░░░▀██▄████████▄▄▄▄██▄▀░░░█─
──█░░░░▀██▀▀▀▀████████▀░░░░█──
───▀▄░░░░▀▄▄▄▄██████▀░░░░▄▀───
─────▀▀▄▄░░░░░░░░░░░░▄▄▀▀─────
─────────▀▀▀▀▀▀▀▀▀▀▀▀─────────
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (b[i] < a[i]) {
			cout << -1;
			return 0;
		}
		q.emplace(b[i], i);
	}
	long long ans = 0;
	while (q.size()) {
		auto p = q.top();
		q.pop();
		int l = (p.second - 1 + n) % n, r = (p.second + 1) % n;
		if ((b[p.second] - a[p.second]) % (b[l] + b[r]) == 0) {
			ans += (b[p.second] - a[p.second]) / (b[l] + b[r]);
			b[p.second] = a[p.second];
			continue;
		}
		if (b[p.second] <= b[l] + b[r]) {
			cout << -1;
			return 0;
		}
		ans += b[p.second] / (b[l] + b[r]);
		b[p.second] %= (b[l] + b[r]);
		if (b[p.second] < a[p.second]) {
			cout << -1;
			return 0;
		}
		q.emplace(b[p.second], p.second);
	}
	cout << ans;

	return 0;
}