#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans += (i % 2 == 0 && x % 2);
	}
	cout << ans;
}
