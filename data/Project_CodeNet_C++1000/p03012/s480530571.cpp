#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int n;
	cin >> n;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	int ans = 99999;
	rep(t, n) {
		int a = 0; int b = 0;
		for (int j = 0; j <= t; j++) {
			a += w[j];
		}
		for (int k = t+1; k < n; k++) {
			b += w[k];
		}
		ans = min(ans, abs(a-b));
	}
	cout << ans << endl;
}
