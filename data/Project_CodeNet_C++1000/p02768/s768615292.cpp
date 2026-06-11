#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

const int MOD = 1e9 + 7;

long long mod_pow(long long a, long long b, long long p = MOD) { // = (a^b) % p //((a^-1) % p) = (a^(p-2)) % p;
	long long res = 1;
	a %= p;

	while (b > 0) {
		if ((b & 1) == 1) res = ((res % p) * (a % p)) % p;
		a = ((a % p) * (a % p)) % p;
		b >>= 1;
	}
	return res;
}

long long  C(long long  n, long long  r) {
	//n!/r!(n-r)!
	cerr << n << " " << r << endl;
	r = max(r, n - r);
	long long  num = 1, den = 1;
	for (int i = r + 1; i <= n; i++) num = (num % MOD * i % MOD) % MOD;
	for (int j = 1; j <= n - r; j++) den = (den % MOD * j % MOD) % MOD;

	return (num % MOD * mod_pow(den, MOD - 2)) % MOD;
}

int main() {

	long long  n, a, b; cin >> n >> a >> b;
	long long  res = ((C(n, a) + C(n, b)) % MOD + 1) % MOD;

	cout << (mod_pow(2, n) - res + MOD) % MOD;

	return 0;
}