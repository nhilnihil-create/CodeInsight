#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	ll r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;
	ll ans = 0;
	vector<bool> win(n, true);
	for (ll i = 0; i < k; ++i) {
		if (t[i] == 'r')ans += p;
		else if (t[i] == 's')ans += r;
		else ans += s;
		cerr << i << ":" << ans << endl;
	}
	for (ll i = k; i < n; ++i) {
		if (t[i] != t[i - k] || (!win[i - k])) {
			if (t[i] == 'r')ans += p;
			else if (t[i] == 's')ans += r;
			else ans += s;
		}
		else {
			win[i] = false;
		}
		cerr << i << ":" << ans << endl;
	}
	cout << ans << endl;
}
