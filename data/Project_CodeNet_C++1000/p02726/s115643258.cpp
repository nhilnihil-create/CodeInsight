
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

static void ABC160D();

int main()
{
	ABC160D();
	fflush(stdout);
	return 0;
}

static void ABC160D()
{
	int N, X, Y;
	getint(N, X, Y);
	
	std::vector<int> dist(N + 1, 0);
	for (int start = 1; start < N; start++) {
		for (int end = start + 1; end <= N; end++) {
			int diff = end - start;
			int passed = abs(X - start) + 1 + abs(Y - end);
			dist[std::min(diff, passed)]++;
		}
	}
	
	for (int d = 1; d < N; d++) {
		printf("%d\n", dist[d]);
	}
}
