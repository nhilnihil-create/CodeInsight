#include <bits/stdc++.h>
using namespace std;

int64_t	modpow(int64_t a, int64_t n, const int64_t mod)
{
	int64_t	result = 1;
	while (n) {
		if (n & 1) result = result * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return result;
}

int	main()
{
	const static int64_t	mod = 1000000007;
	int64_t	m, n;
	cin >> m >> n;
	cout << modpow(m, n, mod) << endl;
}
