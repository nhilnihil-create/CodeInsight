
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

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	int N;
	getint(N);

	std::vector<LLONG> ai(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}

	LLONG sum = 0;
	LLONG sign[] = { 1, -1 };
	for (int i = 0; i < N; i++) {
		sum += sign[i % 2] * ai[i];
	}
	LLONG vol = sum;
	printf("%lld ", vol);
	for (int i = 1; i < N; i++) {
		vol = (ai[i - 1] - (vol / 2)) * 2LL;
		printf("%lld ", vol);
	}
	putchar('\n');
}
