
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
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
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
	LLONG N, K, S;
	getval(N, K, S);

	LLONG other = N - K;
	LLONG otherVal = S + 1;
	if (otherVal > 1000000000LL) {
		otherVal = 1;
	}
	LLONG kCount = K;

	int idx = 0;
	std::vector<LLONG> ai(N);
	while (other || kCount) {
		if (kCount) {
			ai[idx] = S;
			idx++;
			kCount--;
		}
		if (other) {
			ai[idx] = otherVal;
			idx++;
			other--;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%lld\n", ai[i]);
	}
}
