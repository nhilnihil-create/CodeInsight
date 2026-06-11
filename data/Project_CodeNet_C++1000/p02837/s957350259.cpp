#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<vector<int>> c(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int x, y; cin >> x >> y;
			c[i][--x] = y;						
		}
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << n); ++bit) {
		int cnt = 0;
		vector<int> d(n, 0);
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				d[i] = 1;
				cnt++;
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (d[i]) {
				for (int j = 0; j < n; j++) {
					if (c[i][j] == -1) continue;
					if (c[i][j] != d[j]) ok = false;
				}
			}
		}
		if (ok) ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}