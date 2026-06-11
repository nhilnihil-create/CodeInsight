#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int timer, k;
string s;
ll dp[13][2][2][10];
int seen[13][2][2][10];

ll solve(int idx = 0, bool top = 0, bool put = 0, int last = 0) {
	if (idx == (int)s.size()) return put;

	if (seen[idx][top][put][last] == timer)
		return dp[idx][top][put][last];
	seen[idx][top][put][last] = timer;

	ll ans = 0;
	int mx = top ? 9 : s[idx]-'0';
	if (put==0) {
		for (int i = 0; i <= mx; ++i) { //10
			ans += solve(idx + 1, top | (i != mx), (i != 0), i);
		}
	} else {
		for (int i = max(0, last-1); i <= min(mx, min(last+1, 9)); ++i) {
			ans += solve(idx + 1, top | (i != mx), 1, i);
		}
	}
	return dp[idx][top][put][last] = ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> k;
	
	ll lo = 1, hi = 1e12, ans = 0;
	while (lo <= hi) {
		ll mid = (lo+hi)>>1;
		s = to_string(mid);
		timer++;
		if (solve() >= k) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
}
