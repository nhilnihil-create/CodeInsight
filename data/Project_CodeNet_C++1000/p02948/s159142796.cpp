
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

static void ABC137D();

#if 1
int main()
{
	ABC137D();
	fflush(stdout);
	return 0;
}
#endif


static void ABC137D()
{
	int N, M;
	getint(N, M);
	
	std::vector<std::vector<int>> data(M + 1);
	for (int i = 0; i < N; i++) {
		int day, money;
		getint(day, money);
		if (day <= M) {
			data[day].push_back(money);
		}
	}

	std::vector<int> money(M + 1, 0);
	std::priority_queue<int> pque;
	for (int i = 0; i <= M; i++) {
		for (auto it = data[i].begin(); it != data[i].end(); it++) {
			pque.push(*it);
		}
		if (!pque.empty()) {
			money[i] = pque.top(); pque.pop();
		}
	}

	LLONG ans = 0;
	for (int i = 0; i <= M; i++) {
		ans += (LLONG)money[i];
	}
	printf("%lld\n", ans);
}
