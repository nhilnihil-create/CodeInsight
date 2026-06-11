#include <bits/stdc++.h>

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const unsigned int M = 1e9 + 7;

int32_t main() {
	fastio;

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	if(k > n) k = n;
	for(int i = 0; i < n - k; ++i) ans += a[i];
	cout << ans;

	return 0;
}
