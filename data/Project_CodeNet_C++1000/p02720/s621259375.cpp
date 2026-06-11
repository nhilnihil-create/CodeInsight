
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

static void ABC161D();

#if 1
int main()
{
	ABC161D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC161D()
{
	int K;
	getint(K);
	
	std::queue<LLONG> lun;

	for (int i = 1; i <= 9; i++) {
		lun.push(i);
	}

	LLONG ans = 0;
	for (int i = 1; i <= K; i++) {
		ans = lun.front(); lun.pop();
		LLONG mod = ans % 10;
		if (mod) {
			lun.push(ans * 10LL + mod - 1LL);
		}
		lun.push(ans * 10LL + mod);
		if (mod != 9) {
			lun.push(ans * 10LL + mod + 1LL);
		}
	}
	printf("%lld\n", ans);
}
