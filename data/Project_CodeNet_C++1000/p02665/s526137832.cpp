
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

static void Nomura2020C();

#if 1
int main()
{
	Nomura2020C();
	fflush(stdout);
	return 0;
}
#endif

static void Nomura2020C()
{
	int N;
	getint(N);

	std::vector<LLONG> leaves(N + 2, 0);
	for (int i = 0; i <= N; i++) {
		getint(leaves[i]);
	}
	if (N == 0) {
		if (leaves[0] == 1) {
			printf("1\n");
			return;
		}
		else {
			printf("-1\n");
			return;
		}
	}

	if (leaves[0] != 0) {
		printf("-1\n");
		return;
	}

	std::vector<LLONG> sumLeaves(N + 2, 0);
	sumLeaves[N] = leaves[N];
	for (int i = N - 1; i >= 0; i--) {
		sumLeaves[i] = sumLeaves[i + 1] + leaves[i];
	}

	std::vector<LLONG> nodes(N + 2, 0), needNodes(N + 2, 0);
	nodes[0] = 1;
	for (int depth = 1; depth <= N; depth++) {
		nodes[depth] = (nodes[depth - 1] - leaves[depth - 1]) * 2LL;
		if (depth == N) {
			if (nodes[depth] < leaves[depth]) {
				printf("-1\n");
				return;
			}
			nodes[depth] = leaves[depth];
		}
		else {
			if (nodes[depth] <= leaves[depth]) {
				printf("-1\n");
				return;
			}
			nodes[depth] -= leaves[depth];
			nodes[depth] = std::min(sumLeaves[depth + 1], nodes[depth]);
			nodes[depth] += leaves[depth];
		}
	}
	
	LLONG ans = 0;
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		ans += *it;
	}
	printf("%lld\n", ans);
}
