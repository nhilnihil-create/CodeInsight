
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

static void ABC163D();


#if 1
int main()
{
	ABC163D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC163D()
{
	LLONG N, K;
	getint(N, K);
	
	LLONG ans = 0;
	for (LLONG i = K; i <= (N + 1); i++) {
		LLONG ptnMin = (i - 1) * i / 2LL;
		LLONG ptnMax = (i * (2 * N - (i - 1))) / 2LL;
		ans += (ptnMax - ptnMin) + 1;
		ans %= MOD_NUM;
	}
	printf("%lld\n", ans);
}
