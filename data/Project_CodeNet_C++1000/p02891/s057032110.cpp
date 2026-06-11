#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s; ll k; cin >> k;
	bool al = true;
	for (int i = 0; i < s.length() - 1; i++)if (s.at(i) != s.at(i + 1))al = false;
	ll ans = 0;
	if (s.at(0) != s.at(s.length() - 1)) {
		for (int i = 0; i < s.length() - 1; i++) {
			if (s.at(i) == s.at(i + 1)) {
				s.at(i + 1) = 'A';
				ans++;
			}
		}
		ans *= k;
	}
	else if (al == true) ans = s.length() * k / 2;
	else {
		string sl, sm, sr;
		for (int i = 0; i < s.length(); i++) {
			if (s.at(i) != s.at(i + 1)) {
				sl = s.substr(0, i + 1);
				sr = s.substr(i + 1);
				sm = sr + sl;
				break;
			}
		}
		ans += sl.length() / 2;
		ll x = 0;
		for (int i = 0; i < sm.length() - 1; i++) {
			if (sm.at(i) == sm.at(i + 1)) {
				sm.at(i + 1) = 'A';
				x++;
			}
		}
		ans += x * (k - 1);
		for (int i = 0; i < sr.length() - 1; i++) {
			if (sr.at(i) == sr.at(i + 1)) {
				sr.at(i + 1) = 'A';
				ans++;
			}
		}
	}
	cout << ans << endl;
}