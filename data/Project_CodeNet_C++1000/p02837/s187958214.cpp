
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

static void ABC147C();

int main()
{
	ABC147C();
	fflush(stdout);
	return 0;
}

static void ABC147C()
{
	int N;
	getint(N);

	std::vector<std::vector<std::pair<int, int>>> evid(N);
	for (int i = 0; i < N; i++) {
		int ai;
		getint(ai);
		evid[i].resize(ai);
		for (int j = 0; j < ai; j++) {
			getint(evid[i][j].first, evid[i][j].second);
		}
	}

	int maxHonest = 0;
	for (int i = 0; i < (1 << N); i++) {

		bool allOk = true;
		for (int p = 0; p < N; p++) {
			if (!((i >> p) & 0x1)) {
				continue;
			}
			int evdCount = evid[p].size();
			for (int e = 0; e < evdCount; e++) {
				int honest = evid[p][e].second;
				int number = evid[p][e].first - 1;

				int bit = (i >> number) & 0x1;
				if (honest != bit) {
					allOk = false;
					break;
				}
			}
			if (!allOk) break;
		}
		if (allOk) {
			int honestCount = 0;
			int bits = i;
			while (bits) {
				if (bits & 0x1) honestCount++;
				bits >>= 1;
			}
			maxHonest = std::max(honestCount, maxHonest);
		}
	}
	printf("%d\n", maxHonest);
}
