#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	ll a[n], base[65];
	memset(base, 0, sizeof base);
	for(int i = 0; i < n; ++i)cin >> a[i];
	string s; cin >> s;
	for(int i = n - 1; ~i; --i) {
		bool contains = true;
		for(int bit = 0; bit < 61; ++bit) {
			if(a[i] >> bit & 1) {
				if(!base[bit]) {
					contains = false;
					base[bit] = a[i];
					break;
				}
				a[i] ^= base[bit];
			}
		}
		if(!contains) {
			if(s[i] == '1') {
				cout << "1\n";
				return;
			}
		}
	}
	cout << "0\n";
}

int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}