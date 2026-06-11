#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0, lr = 0, rl = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans += (s[i] == s[i + 1]);
		lr += (s[i] != s[i + 1] && s[i] == 'L');
		rl += (s[i] != s[i + 1] && s[i] == 'R');
	}
	while (k && lr && rl) {
		--lr;
		--rl;
		--k;
		ans += 2;
	}
	if (s[0] == 'L') {
		while (k && lr) {
			--k;
			++ans;
			--lr;
		}
	}
	else {
		while (k && rl) {
			--k;
			++ans;
			--rl;
		}
	}
	if (s.back() == 'R') {
		while (k && lr) {
			--k;
			++ans;
			--lr;
		}
	}
	else {
		while (k && rl) {
			--k;
			++ans;
			--rl;
		}
	}
	cout << ans << '\n';
}
