#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; string s; cin >> n >> s;
	ll r_cnt = 0;
	ll g_cnt = 0;
	ll b_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') r_cnt++;
		if (s[i] == 'G') g_cnt++;
		if (s[i] == 'B') b_cnt++;
	}
	ll tmp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int k = 2 * j - i;
			if (n <= k) continue;
			if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
				tmp++;
			}
		}
	}
	ll ans = r_cnt * g_cnt * b_cnt - tmp;
	cout << ans << endl;
	return 0;
}