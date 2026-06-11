#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k, r, s, p; cin >> n >> k >> r >> s >> p;
	string t; cin >> t;
	vector<bool> skip(n, false);
	ll ans = 0;
	for (int i = 0; i < t.size(); i++) {
		if (k <= i && t[i] == t[i - k] && !skip[i - k]) {
			skip[i] = true;
			continue;
		}
		if (t[i] == 'r') {
			ans += p;
		}
		else if (t[i] == 's') {
			ans += r;
		}
		else if (t[i] == 'p') {
			ans += s;
		}
	}
	cout << ans << endl;
    return 0;
}