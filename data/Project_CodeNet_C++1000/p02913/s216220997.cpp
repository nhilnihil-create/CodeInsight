
// E - Who Says a Pun?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
string S;

bool is_ok(ll k) {
	map<string, int> pos;
	for (int i=0; i<=S.size() - k; i++) {
		string sub = S.substr(i, k);
		if (pos.count(sub) == 0) {
			pos[sub] = i;
		} else {
			if (pos[sub] + k <= i) {
				return true;
			}
		}
	}

	return false;
}

ll find_max_ok(ll lower, ll upper) {
	if (!is_ok(lower)) return 0; // 存在しない

	ll ok = lower;
	ll ng = upper;

	while(ng - ok > 1) {
		ll trying = (ng + ok) / 2;

		if (is_ok(trying)) {
			ok = trying;
		} else {
			ng = trying;
		}
	}

	return ok;
}

int main() {
	cin >> N;
	cin >> S;

	int ans = find_max_ok(1, S.size());

	cout << ans << endl;

	return 0;
}