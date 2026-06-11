#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
signed main(void) {
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	vector<int>a(n), m(n + 1);
	for (int i = 0; i < n; i++)
		a[i] = s[n - 1 - i] - '0';

	int ans = 0;
	if (p == 2 || p == 5) {
		for (int i = 0; i < n; i++)
			if (a[i] % p == 0)
				ans += n - i;
		cout << ans << endl;
		return 0;
	}

	int t = 1;
	for (int i = 0; i < n; i++) {
		m[i + 1] = (m[i] + a[i] * t) % p;
		t = (t * 10) % p;
	}

	vector<int>cnt(p);
	for (int i = 0; i <= n; i++) {
		ans += cnt[m[i]];
		cnt[m[i]]++;
	}

	cout << ans << endl;
	return 0;
}