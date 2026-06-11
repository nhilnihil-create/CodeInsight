
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

static void ABC164D();

#if 1
int main()
{
	ABC164D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC164D()
{
	std::string orgs;
	std::cin >> orgs;

	std::vector<LLONG> counter(2019, 0);
	int sLen = orgs.length();

	int factor = 1;
	int curVal = 0;
	counter[curVal]++;
	for (int i = sLen - 1; i >= 0; i--) {
		int num = orgs[i] - '0';
		curVal = (curVal + num * factor) % 2019;
		counter[curVal]++;
		factor = (factor * 10) % 2019;
	}

	LLONG ans = 0;
	for (int i = 0; i < 2019; i++) {
		ans += (counter[i] * (counter[i] - 1LL)) / 2LL;
	}
	printf("%lld\n", ans);
}
