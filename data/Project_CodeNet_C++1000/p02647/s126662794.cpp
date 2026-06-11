
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

static void TokioMarine2020C();

#if 1
int main()
{
	TokioMarine2020C();
	fflush(stdout);
	return 0;
}
#endif

static void TokioMarine2020C()
{
	int N, K;

	getint(N, K);
	std::vector<LLONG> ai(N, 0);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}

	for (int k = 0; k < K; k++) {
		std::vector<LLONG> bi(N, 0);
		for (int i = 0; i < N; i++) {
			LLONG left = std::max<LLONG>(0, i - ai[i]);
			LLONG right = std::min<LLONG>(N - 1, i + ai[i]);
			bi[left]++;
			if (right < N - 1) {
				bi[right + 1]--;
			}
		}

		ai[0] = bi[0];
		LLONG minRight = MOD_NUM;
		for (int i = 1; i < N; i++) {
			ai[i] = ai[i - 1] + bi[i];
			minRight = std::min(ai[i], minRight);
		}
		if (minRight >= N) {
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%lld ", ai[i]);
	}
	putchar('\n');
}
