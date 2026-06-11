#include<bits/stdc++.h>
#define int long long
using namespace std;
int test[12345678], test1[12345678];
signed main() {
	int n, k, c, cnt = 1, mae = 0; string s; cin >> n >> k >> c >> s;
	for (int h = 0; h < n; h++) {
		if (s[h] == 'o') {
			if (cnt == 1) { test[cnt] = h + 1; cnt++; mae = h; }
			else if (h - mae > c) {
				test[cnt] = h + 1; cnt++; mae = h;
			}
		}
		if (cnt > k) { break; }
	}
	cnt = k;
	for (int h = n - 1; h >= 0; h--) {
		if (s[h] == 'o') {
			if (cnt == k) { test1[cnt] = h + 1; cnt--; mae = h; }
			else if (mae - h > c) {
				test1[cnt] = h + 1; cnt--; mae = h;
			}
		}
		if (cnt == 0) { break; }
	}
	for (int h = 1; h <= k; h++) {
		if (test[h] == test1[h]) {
			cout << test[h] << endl;
		}
	}
	return 0;
}