#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	ll k; cin >> k;
	bool allSame = true;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] != s[0]) allSame = false;
	}
	ll ans = 0;
	if (allSame) {
		ans = k * s.size() / 2;
		cout << ans << endl;
		return 0;
	}
	ll cnt = 1;
	for (ll i = 1; i < s.size(); i++) {			
		if (s[i] == s[i - 1]) {
			cnt++;
		}
		else {
			ans += cnt / 2;
			cnt = 1;
		}			
	}
	ans += cnt / 2;
	ans *= k;
	if (s[0] == s[s.size() - 1]) {
		ll leftCnt = 0;
		ll rightCnt = 0;
		ll i = 1;
		while (true) {
			if (s[i] == s[0]) leftCnt++;
			else break;
				i++;
		}
		i = 1;
		while (true) {
			if (s[s.size() - 1 - i] == s[s.size() - 1]) rightCnt++;
			else break;
			i++;
		}
		if (0 < leftCnt) leftCnt++;
		if (0 < rightCnt) rightCnt++;
		ans -= (leftCnt / 2 + rightCnt / 2 - (leftCnt + rightCnt) / 2) * (k - 1);
	}
	cout << ans << endl;
	return 0;
}