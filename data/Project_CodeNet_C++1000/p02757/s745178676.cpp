#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000;
const ll mod = 1000000007;
ll test[12345678], res[12345678], aa[1234][1234], bb[1234][1234];
ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
char maze[1234][1234];
signed main() {
	ll n, m, k, sum = 0, cnt = 1, ans = 0; cin >> n >> m;
	string s; cin >> s;
	if (m % 10 == 0) {
		for (int h = 0; h < n; h++) { if ((ll)(s[h] - '0') % 10 == 0) { ans += h + 1; } }
		cout << ans << endl; return 0;
	}
	if (m % 2 == 0) {
		for (int h = 0; h < n; h++) { if ((ll)(s[h] - '0') % 2 == 0) { ans += h + 1; } }
		cout << ans << endl; return 0;
	}
	if (m % 5 == 0) {
		for (int h = 0; h < n; h++) { if ((ll)(s[h] - '0') % 5 == 0) { ans += h + 1; } }
		cout << ans << endl; return 0;
	}
	reverse(s.begin(), s.end()); test[0] = 1;
	for (int h = 0; h < s.size(); h++) {
		sum = ((ll)(s[h] - '0') * cnt + sum) % m;
		test[sum]++; //cout << sum << endl;
		cnt *= 10; cnt %= m;
	}
	for (int h = 0; h < m; h++) {
		ans += test[h] * (test[h] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}