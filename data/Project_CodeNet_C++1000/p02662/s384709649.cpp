#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	const int mod = 998244353;
	int d[3005][3005]{};
	d[0][0] = 1;
	for(int i =1; i<=n; ++i) {
		int a; cin >> a;
		for(int j =0; j<=s; ++j) {
			d[i][j] += 2 * d[i - 1][j];
			d[i][j] %= mod;
			if (j - a >= 0) {
				d[i][j] += d[i - 1][j - a];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[n][s];
}