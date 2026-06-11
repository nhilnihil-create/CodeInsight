#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int n, m, x, y, kx, ky, ans, i, f[N], cnt[N];
int find_root(int x) {
	if (f[x] == x) return x;
	return f[x] = find_root(f[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		f[i] = i;
		cnt[i] = 1;
	}
	while (m--) {
		cin >> x >> y;
		kx = find_root(x);
		ky = find_root(y);
		if (kx != ky) {
			f[kx] = ky;
			cnt[ky] += cnt[kx];
		}
	}
	for (i = 1; i <= n; i++) if (f[i] == i) ans = max(ans, cnt[i]);
	cout << ans << '\n';
	return 0;
}