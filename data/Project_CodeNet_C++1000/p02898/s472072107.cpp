#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int n, k; cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		if (t >= k) ans++;
	}
	cout << ans << '\n';
}
