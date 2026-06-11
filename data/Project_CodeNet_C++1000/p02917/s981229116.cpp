#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, ans, a[200], b[200];
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 0;
	cin >> n;
	for(int i = 0; i < n-1; ++i) cin >> b[i];
	a[0] = b[0];
	for(int i = 1; i < n; ++i) {
		a[i] = min(b[i], b[i-1]);
	}
	a[n-1] = b[n-2];
	for(int i = 0; i < n; ++i) ans += a[i];
	cout << '\n' << ans;
}