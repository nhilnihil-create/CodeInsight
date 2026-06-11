#include <iostream>
#define int long long
using namespace std;

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n % 2 == 0) return powmod((a * a) % mod, n / 2, mod);
	return (a * powmod(a, n - 1, mod)) % mod;
}

int mod = 1000000007;
int x, y;
int fact[2000001];
int finv[2000001];
int inv[2000001];

int comb(int n, int k) {
	return fact[n] * finv[k] % mod * finv[n - k] % mod;
}

signed main() {
	cin >> x >> y;
	
	int i;
	fact[0] = fact[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (i = 2; i <= 2000000; i++) {
		fact[i] = i * fact[i - 1] % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
	
	if ((x + y) % 3 != 0) { cout << 0 << endl; return 0; }
	int k = (x + y) / 3;
	
	x -= k;
	y -= k;
	if (x < 0 || y < 0) { cout << 0 << endl; return 0; }
	
	cout << comb(k, x) << endl;
	return 0;
}