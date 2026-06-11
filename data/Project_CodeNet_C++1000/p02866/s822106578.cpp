#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
	int n;
	cin >> n;
	vector<int> cnt_in_depth(n), d(n);
	int f;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		f = d[0];
	}
	sort(begin(d), end(d));
	if (f != 0 || d[0] != 0) {
		cout << 0;
		return 0;
	}
	cnt_in_depth[0] = 1;
	int res = 1;
	for (int i = 1; i < n; i++) {
		int x = d[i];
		res = (1ll * res * (cnt_in_depth[x - 1])) % mod;
		cnt_in_depth[x]++;
	}
	cout << res;
	return 0;
}