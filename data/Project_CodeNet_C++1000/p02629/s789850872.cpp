#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
	ll n; cin >> n; --n;
	ll mx = ll(1e15) + 1;
	ll now = 26;
	vector<ll> v;
	while (now < mx * 26) {
		v.push_back(now);
		now *= 26;
	}
	int len = 1;
	for (ll i: v) {
		if (n < i) {
			string ans = "";
			for (int j = 0; j < len; ++j) {
				ans.push_back(char('a' + n % 26));
				n /= 26;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
			break;
		}
		else {
			n -= i;
			++len;
			continue;
		}
	}
}
