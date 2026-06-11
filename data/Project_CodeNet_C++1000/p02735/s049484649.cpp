
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

static void AGC043A();

#if 1
int main()
{
	AGC043A();
	fflush(stdout);
	return 0;
}
#endif

static void AGC043A()
{
	int H, W;
	getint(H, W);

	std::vector<std::string> grid(H);
	for (int h = 0; h < H; h++) {
		std::cin >> grid[h];
	}

	std::vector<std::vector<std::pair<int, int>>> path(H, std::vector<std::pair<int, int>>(W, std::pair<int, int>((int)MOD_NUM, (int)MOD_NUM)));
	std::queue<std::pair<int, int>> que;
	que.push(std::pair<int, int>(0, 0));

	path[0][0].first = 0;
	path[0][0].second = (grid[0][0] == '#') ? 1 : 0;
	while (!que.empty()) {
		int dh[] = { 0, 1 };
		int dw[] = { 1, 0 };

		std::pair<int, int> pos = que.front(); que.pop();
		int pathCount = path[pos.first][pos.second].first;
		int blackCount = path[pos.first][pos.second].second;
		for (int i = 0; i < 2; i++) {
			int nh = pos.first + dh[i];
			int nw = pos.second + dw[i];

			if ((nh >= 0) && (nw >= 0) && (nh < H) && (nw < W)) {
				int nbCount = blackCount;
				if ((grid[nh][nw] == '#') && (grid[pos.first][pos.second] != '#')) {
					nbCount++;
				}

				if ((nbCount < path[nh][nw].second) ||
					((nbCount == path[nh][nw].second) && ((pathCount + 1) < path[nh][nw].first))) {
					path[nh][nw].first = pathCount + 1;
					path[nh][nw].second = nbCount;
					que.push(std::pair<int, int>(nh, nw));
				}
			}
		}
	}

	printf("%d\n", path[H - 1][W - 1].second);
}