
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

static void ABC158E();

#if 1
int main()
{
	ABC158E();
	fflush(stdout);
	return 0;
}
#endif

static void ABC158E()
{
	int N, P;
	getint(N, P);

	std::string orgs;
	std::cin >> orgs;

	if ((P == 2) || (P == 5)) {
		LLONG ans = 0;
		for (int i = N - 1; i >= 0; i--) {
			int num = orgs[i] - '0';
			if (num % P == 0) {
				ans += i + 1;
			}
		}
		printf("%lld\n", ans);
		return;
	}

	int mod = 0;
	int factor = 1;
	std::vector<LLONG> counter(P, 0);
	counter[0] = 1;
	for (int i = N - 1; i >= 0; i--) {
		int num = orgs[i] - '0';

		mod = (mod + (num * factor)) % P;
		counter[(int)mod]++;
		factor = (factor * 10) % P;
	}

	LLONG ans = 0;
	for (int i = 0; i < P; i++) {
		ans += (counter[i] * (counter[i] - 1LL)) / 2LL;
	}
	printf("%lld\n", ans);
}
