#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC147D();

#if 1
int main()
{
	ABC147D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC147D()
{
	int N;
	getint(N);

	std::vector<LLONG> an(N, 0);
	for (int i = 0; i < N; i++) {
		getint(an[i]);
	}

	LLONG ans = 0;
	LLONG bit = 1, two_factor = 1;
	for (int shift = 0; shift < 60; shift++) {
		bit = 1LL << shift;
		LLONG one = 0, zero = 0;
		for (int i = 0; i < N; i++) {
			if (an[i] & bit) {
				one++;
			}
			else {
				zero++;
			}
		}
		ans = (ans + ((one * zero % MOD_NUM) * two_factor) % MOD_NUM) % MOD_NUM;
		two_factor = (two_factor * 2LL) % MOD_NUM;
	}
	printf("%lld\n", ans);
}
