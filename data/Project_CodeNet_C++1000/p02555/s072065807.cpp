#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MOD = (int)(1e+9) + 7;
int S, N;
vector<ll> fac, finv, inv;

void input_init(void) {
	cin >> S;
	fac.resize(S);
	finv.resize(S);
	inv.resize(S);
	N = S / 3;
}

void comb_init() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < S; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll comb(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve(void) {
	ll sum = (ll)0;
	for (int k = 1; k <= N; ++k) {
		int b = k - 1;
		int a = S - 3 * k + b;
		sum += (comb(a, b) % MOD);
		sum %= MOD;
	}
	return sum;
}

int main(void) {
	input_init();
	comb_init();
	ll ans = solve();
	cout << ans << '\n';
	return 0;
}
