#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n; string s; cin >> n >> s;
	ll Nr = 0;
	ll Ng = 0;
	ll Nb = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == 'R') Nr++;
		if (s[i] == 'G') Ng++;
		if (s[i] == 'B') Nb++;	
	}
	if (Nr == 0 || Ng == 0 || Nb == 0) {
		cout << 0 << endl;
		return 0;
	}
	ll sum = Nr * Ng * Nb;
	ll tmp = 0;
	for (ll i = 0; i < n - 2; i++) {
		for (ll j = i + 1; j < n - 1; j++) {
			ll k = 2 * j - i;
			if (n - 1 < k) continue;
			if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
				tmp++;
			}			
		}
	}
	cout << max(0LL, sum - tmp) << endl;
	return 0;
}