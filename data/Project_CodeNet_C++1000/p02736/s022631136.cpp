#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

/*
	Lookout for overflows!!
	Check array sizes!!
	Clear before test cases!!
	Use the correct modulo!!
	Check for corner cases!!
	Are you forgetting something?!
*/

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

int ncr(int n,int k) { // modulo 2
	if(n < k) return 0;
	for(int i = 0; i < 23; i++) {
		int b1 = ((n >> i) & 1);
		int b2 = ((k >> i) & 1);
		if(!b1 && b2) return 0;
	}
	return 1;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		s[i]--;
		int r1 = i, r2 = n - 1 - r1;
		if(s[i] == '1')
			ans ^= ncr(r1 + r2, r1);
	}
	if(ans) {
		cout << 1;
		return;
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			cout << 0;
			return;
		}
		if(s[i] == '2') s[i] = '1';
	}
	ans = 0;
	for(int i = 0; i < n; i++) {
		int r1 = i, r2 = n - 1 - r1;
		if(s[i] == '1')
			ans ^= ncr(r1 + r2, r1);
	}
	if(ans) {
		cout << 2;
	}
	else {
		cout << 0;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	for(int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}