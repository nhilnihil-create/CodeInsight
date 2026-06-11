#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 10001;

vector<int> f(MAXN, 0);

inline void precalc() {
	for (int x = 1; x * x <= MAXN; x++) {
		for (int y = 1; y * y <= MAXN; y++) {
			for (int z = 1; x * x + y * y + z * z + x * y + y * z + z * x < MAXN; z++) {
				f[z * z + y * y + x * x + x * y + y * z + z * x]++;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	precalc();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << f[i] << '\n';
	}
}
