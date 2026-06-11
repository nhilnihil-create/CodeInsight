#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	LLONG N, A, B;
	get(N, A, B);

	LLONG ans = 0;
	LLONG diff = tp_abs(A - B);
	if (diff % 2 == 0) {
		ans = diff / 2LL;
	}
	else {
		LLONG big = std::max(A, B);
		LLONG sml = std::min(A, B);

		ans = (big - sml) / 2 + sml;

		ans = std::min(ans, (N - big + 1) + (N - (sml + N - big + 1)) / 2);
	}
	printf("%lld\n", ans);
}
