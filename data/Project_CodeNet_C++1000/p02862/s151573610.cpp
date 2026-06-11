#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll modpow(ll x, ll y, ll m = mod) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= m; }
		x = x * x % mod; y /= 2;
	}
	return res;
}
ll iti[12345678], cnt[12345678], cost[4321][4321];
signed main() {
	ll n, m, cnt1 = 0, cnt2 = 0, ans = 0; cin >> n >> m;
	if ((n + m) % 3 != 0) { cout << 0 << endl; return 0; }
	if (n >= m) { swap(n, m); }
	if (2 * n < m) { cout << 0 << endl; return 0; }
	cnt2 = (n + m) / 3;
	while (true) {
		if (2 * n == m) { break; }
		cnt1++; cnt2--; n -= 2; m--;
	}
	ll N = cnt1 + cnt2, A = min(cnt1, cnt2), X = 1, Y = 1;
	for (int h = 1; h <= A; h++) { Y *= h; Y %= mod; }
	for (int h = N - A + 1; h <= N; h++) { X *= h; X %= mod; }
	//cout << X << ' ' << Y << endl;
	cout << X * modpow(Y, mod - 2) % mod << endl;
	cin >> n; return 0;
}