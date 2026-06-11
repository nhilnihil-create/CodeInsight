
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void ABC147D();

int main()
{
	ABC147D();
	fflush(stdout);
	return 0;
}

template <class _T> static _T tp_modpow(_T a, _T n, _T mod = (_T)1) {
	_T ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}
template <class _T> static _T tp_modinv(_T a, _T mod) {
	return tp_modpow<_T>(a, mod - 2, mod);
}

static void ABC147D()
{
	int N;
	getint(N);

	std::vector<LLONG> ai(N);
	std::vector<std::vector<int>> bits(N, std::vector<int>(60, 0));
	for (int i = 0; i < N; i++) {
		if (i) bits[i] = bits[i - 1];

		getint(ai[i]);

		int bit = 0;
		LLONG tmp = ai[i];
		while (tmp) {
			if (tmp & 1LL) bits[i][bit]++;
			tmp >>= 1LL;
			bit++;
		}
	}
	
	std::vector<LLONG> sum(60, 0);
	for (int i = 0; i < N - 1; i++) {
		for (int bit = 0; bit < 60; bit++) {
			int on = bits[N - 1][bit] - bits[i][bit];
			if ((ai[i] >> (LLONG)bit) & 1LL) {
				sum[bit] += (N - i - 1) - on;
			}
			else {
				sum[bit] += on;
			}
		}
	}

	LLONG ans = 0;
	for (int bit = 0; bit < 60; bit++) {
		ans = (ans + (sum[bit] % MOD_NUM) * tp_modpow<LLONG>(2LL, bit, MOD_NUM)) % MOD_NUM;
	}
	printf("%lld\n", ans);
}
