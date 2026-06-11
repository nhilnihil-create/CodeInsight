#include <bits/stdc++.h>
using namespace std;

#define int long long

int pow_mod (int a, int b, int p) {
	int res = 1, t = a;
	while (b) {
		if (b & 1)
			(res *= t) %= p;
		(t *= t) %= p;
		b >>= 1;
	}
	return res;
}

signed main () {
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	if (p == 2 || p == 5) {
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (((int)(s[i] - '0')) % p == 0LL)
				ans += i + 1;
		}
		cout << ans << '\n';
	}
	else {
		vector < int > pref(n + 1, 0);
		map < int, int > prefs;
		prefs[0] = 1;
		for (int i = 0; i < n; ++i) {
			pref[i + 1] = (pref[i] * 10LL + ((int)(s[i] - '0'))) % p;
			++prefs[((pref[i + 1]) * pow_mod(10, n - i - 1, p)) % p];
		}
		long long ans = 0LL;
		for (auto pr: prefs) 
			ans += (((long long) pr.second) * (((long long) pr.second) - 1LL)) / 2LL;
		cout << ans << '\n';
	}
}
