#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll lr, rw;
	ll ans = mod;
	ll buf;
	ll i, j;

	lr = 0;	rw = 0;
	for (i = 0; i <= n; i++) {
		if (s[i] == 'R')rw++;
	}
	for (i = 0; i <= n; i++) {
		
		if (lr == rw) {
			buf = lr;
		}
		else if (lr > rw) {
			buf = rw;
			buf += lr - rw;
		}
		else {
			buf = lr;
			buf += rw - lr;
		}
		if (buf < ans)ans = buf;
		if (i == n)break;
		if (s[i] == 'W')lr++;
		else rw--;
	}

	cout << ans << endl;
	return 0;
}
