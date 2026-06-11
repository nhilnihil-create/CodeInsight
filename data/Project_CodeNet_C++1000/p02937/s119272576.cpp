#include <iostream>
#include <vector>
using namespace std;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;
int main() {
	string s, t;
	cin >> s >> t;
	vector<ll> a[26];
	rep(i, s.size()) a[s[i] - 'a'].push_back(i);
	ll lap = 0, k = 0;
	bool ch = 0;
	for (auto c : t) {
		int m = c - 'a';
		if (a[m].empty()) {
			ch = 1;
			break;
		}
		auto itr = lower_bound(a[m].begin(), a[m].end(), k);
		if (itr == a[m].end()) {
			k = *a[m].begin() + 1;
			lap++;
		} else
			k = *itr + 1;
	}
	ll ans = s.size() * lap + k;
	if (ch)
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}
