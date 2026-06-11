#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;
int main() {
	ll n, k, ans = 1;
	const ll mod = 7 + 1e9;
	cin >> n >> k;
	vector<int> s(n + 2);
	rep (i, n + 1) s[i + 1] = (s[i] + i + 1) % mod;;
	for (int i = k; i <= n; i++) {
		ans = (ans + 1 + s[n] - s[n - i] - s[i - 1]) % mod;
	}
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}
