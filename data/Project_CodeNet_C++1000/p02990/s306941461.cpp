#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1'000'000'007;
const int size_max = 2010;

long long fac[size_max], finv[size_max];

long long mpow(long long a, long long b);
void com_init();
long long com(long long n, long long k);

int main()
{
	int n, b;
	cin >> n >> b;
	int r = n - b;

	com_init();
	for (int i = 1; i <= min(b, r + 1); i++) {
		cout << (com(r + 1, i) * com(b - 1, i - 1)) % mod << endl;
	}
	for (int i = min(b, r + 1) + 1; i <= b; i++) {
		cout << 0 << endl;
	}

	return 0;
}

long long mpow(long long a, long long b)
{
	long long t = a;
	long long ans = 1;
	for (int i = 0; b != 0; i++) {
		if ((b & 1) == 1) {
			ans *= t;
			ans %= mod;
		}
		t *= t;
		t %= mod;
		b >>= 1;
	}

	return ans;
}

void com_init()
{
	fac[0] = fac[1] = 1;

	for (int i = 2; i < size_max; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}

	finv[size_max - 1] = mpow(fac[size_max - 1], mod - 2);

	for (int i = size_max - 2; i >= 2; i--) {
		finv[i] = finv[i + 1] * (i + 1) % mod;
	}
	finv[0] = finv[1] = 1;
}

long long com(long long n, long long k)
{
	if (n < k) {
		return 0;
	}

	if (n < 0 || k < 0) {
		return 0;
	}

	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}