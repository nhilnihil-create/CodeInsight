
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

static void ABC166E();

#if 1
int main()
{
	ABC166E();
	fflush(stdout);
	return 0;
}
#endif


static void ABC166E()
{
	int N;
	getint(N);

	std::vector<std::pair<int, int>> ai(N);
	std::map<int, std::set<int>> amn, apn;
	for (int i = 0; i < N; i++) {
		ai[i].first = i + 1;
		getint(ai[i].second);
		
		int aplusn = ai[i].first + ai[i].second;
		apn[aplusn].insert(ai[i].first);

		int aminusn = ai[i].first - ai[i].second;
		if (aminusn > 0) {
			amn[aminusn].insert(ai[i].first);
		}
	}
	
	LLONG ans = 0;
	for (int i = 0; i < N; i++) {
		int aplusn = ai[i].first + ai[i].second;
		int pair = amn[aplusn].size();
		int aminusn = ai[i].first - ai[i].second;
		int pair2 = apn[aminusn].size();
		ans += (LLONG)(pair + pair2);
	}
	printf("%lld\n", ans / 2LL);
}
