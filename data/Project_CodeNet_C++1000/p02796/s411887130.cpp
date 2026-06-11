
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

static void Keyence2020B();

int main()
{
	Keyence2020B();
	fflush(stdout);
	return 0;
}

static void Keyence2020B()
{
	int N;
	getint(N);

	std::vector<std::pair<int, int>> robots(N);
	for (int i = 0; i < N; i++) {
		getint(robots[i].first, robots[i].second);
	}

	std::sort(robots.begin(), robots.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.first < b.first;
	});

	std::vector<int> dp(N + 1, 0);
	dp[0] = dp[1] = 1;
	int lastR = robots[0].first + robots[0].second;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1];
		int nowLeft = robots[i - 1].first - robots[i - 1].second;
		int nowRight = robots[i - 1].first + robots[i - 1].second;
		if (nowLeft >= lastR) {
			dp[i]++;
			lastR = nowRight;
		}
		else if (nowRight < lastR) {
			lastR = nowRight;
		}
	}
	printf("%d\n", dp[N]);
}
