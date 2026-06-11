
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
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
static const LLONG MOD_NUM = 1000000007;//998244353;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	LLONG S;
	getval(S);

	LLONG x0 = 0, x1, x2;
	LLONG y0 = 0, y1, y2;

	int digit = 0;
	LLONG tmp = S;
	while (tmp /= 10) {
		digit++;
	}
	if (digit < 9) {
		x1 = S;
		y1 = 0;
		x2 = 0;
		y2 = 1;
	}
	else {
		x1 = 1e9;
		if (S % x1 == 0) {
			y2 = S / x1;
			x2 = 0;
		}
		else {
			LLONG tmps = S + x1;
			y2 = tmps - tmps % x1;
			y2 /= x1;
			x2 = x1 - (tmps % x1);
		}
		y1 = 1;
	}
	printf("%lld %lld %lld %lld %lld %lld\n", x0, y0, x1, y1, x2, y2);
}
