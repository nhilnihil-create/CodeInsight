#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[12345678][2], aa[1234][1234], bb[1234][1234];
signed main() {
	int n, m = 0, k, z = 0, cnt = 1, ans = 0;
	cin >> n >> k;
	if (k > (n - 1)* (n - 2) / 2) { cout << -1 << endl; return 0; }
	for (int h = 2; h <= n; h++) {
		test[m][0] = 1; test[m][1] = h; m++;
	}
	cnt = (n - 1) * (n - 2) / 2 - k;
	for (int h = 2; h <= n; h++) {
		for (int i = h + 1; i <= n; i++) {
			if (cnt == 0) { z++; break; }
			test[m][0] = h; test[m][1] = i; m++; cnt--;
		}
		if (z == 1) { break; }
	}
	cout << m << endl;
	for (int h = 0; h < m; h++) {
		cout << test[h][0] << ' ' << test[h][1] << endl;
	}
	return 0;
}