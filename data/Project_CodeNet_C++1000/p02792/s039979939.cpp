#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	ll bans = 0;
	string t = to_string(n);
	for (ll a = 1; a <= n; ++a) {
		string s = to_string(a);
		if (s.back() != '0') {
			if (s.front() == s.back() && (s.back() - '0') <= n)++ans;
			if (10 * (s.back() - '0') + (s.front() - '0') <= n)++ans;
			if (t.size() > 2) {
				if (s.back() < t.front()) {
					string preans;
					for (ll i = 0; i < t.size() - 2; ++i) {
						preans += "1";
					}
					preans += "0";
					ans += stol(preans);
				}
				else if (s.back() == t.front()) {
					string preans;
					for (ll i = 0; i < t.size() - 3; ++i) {
						preans += "1";
					}
					preans += "0";
					ans += stol(preans);
					if (s.front() > t.back()) {
						ans += max(0, stoi(t.substr(1, t.size() - 2)));
					}
					else {
						ans += stol(t.substr(1, t.size() - 2)) + 1;
					}
				}
				else {
					string preans;
					for (ll i = 0; i < t.size() - 3; ++i) {
						preans += "1";
					}
					preans += "0";
					ans += stol(preans);
				}
			}
		}
		//cerr << a << " " << ans - bans << endl;
		bans = ans;
	}
	cout << ans << endl;
}