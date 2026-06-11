
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

static void ABC148E();

int main()
{
	ABC148E();
	fflush(stdout);
	return 0;
}

static void ABC148E()
{
	LLONG N;
	getint(N);

	if (N % 2){
		printf("0\n");
		return;
	}
	LLONG ans = 0;
	LLONG divider = 10;
	while (divider <= N) {
		ans += N / divider;
		divider *= 5LL;
	}
	printf("%lld\n", ans);
}
