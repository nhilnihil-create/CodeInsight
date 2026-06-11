#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
int N, K;
ll mul(ll a, ll b) {
	return (a%MOD)*(b%MOD) % MOD;
}
ll add(ll a, ll b) {
	return ((a%MOD)+(b%MOD) + MOD) % MOD;
}
ll mpow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return mul(a, mpow(a, b - 1));
	ll tmp = mpow(a, b / 2);
	return mul(tmp, tmp);
}

ll multiple[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	ll ans = 0;
	for (int i = K; i >= 1; i--) {
		multiple[i] = mpow(K / i, N);
		for (int j = 2 * i; j <= K; j += i) multiple[i] = add(multiple[i], -multiple[j]);
		ans = add(ans, multiple[i] * i);
	}
	cout << ans << '\n';
	return 0;
}