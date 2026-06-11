
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

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	int N;
	getint(N);

	std::vector<int> hi(N, 0);
	for (int i = 0; i < N; i++) {
		getint(hi[i]);
	}

	int maxm = 0;
	int mov = 0;
	for (int i = N - 1; i > 0; i--) {
		if (hi[i] <= hi[i - 1]) {
			mov++;
		}
		else {
			mov = 0;
		}
		maxm = std::max(maxm, mov);
	}
	printf("%d\n", maxm);
}
