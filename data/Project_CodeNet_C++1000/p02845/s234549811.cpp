
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

static void sumitrust2019E();

int main()
{
	sumitrust2019E();
	fflush(stdout);
	return 0;
}

static void sumitrust2019E()
{
	int N;
	getint(N);

	std::vector<LLONG> member(3, 0);
	LLONG ans = 1;
	for (int i = 1; i <= N; i++) {
		int ai;
		getint(ai);

		int ptn = 0;
		for (int m = 0; m < 3; m++) {
			if (ai == member[m]) {
				ptn++;
			}
		}
		ans = (ans * ptn) % MOD_NUM;
		for (int m = 0; m < 3; m++) {
			if (ai == member[m]) {
				member[m]++;
				break;
			}
		}
	}
	printf("%lld\n", ans);
}
