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

static void ABC138E();

#if 1
int main()
{
	ABC138E();
	fflush(stdout);
	return 0;
}
#endif

static void ABC138E()
{
	std::string si, ti;

	std::cin >> si;
	std::cin >> ti;

	std::vector<int> sParts('z' - 'a' + 1, 0), tParts('z' - 'a' + 1, 0);

	int slen = si.size();
	for (int i = 0; i < slen; i++) {
		sParts[si[i] - 'a']++;
	}

	int tlen = ti.size();
	for (int i = 0; i < tlen; i++) {
		tParts[ti[i] - 'a']++;
	}
	//	t の構成要素を全部持っているかチェック
	for (int i = 0; i < ('z' - 'a' + 1); i++) {
		if (tParts[i] && !sParts[i]) {
			printf("-1\n");
			return;
		}
	}

	//	次のアルファベットは何文字目に出現するか
	std::vector<std::vector<int>> next(slen, std::vector<int>('z' - 'a' + 1, -1));
	next[slen - 1][si[slen - 1] - 'a'] = slen - 1;
	for (int i = slen - 2; i >= 0; i--) {
		next[i] = next[i + 1];
		next[i][si[i] - 'a'] = i;
	}

	LLONG ans = 0;
	int tPos = 0;
	int nowPos = 0;
	while (tPos < tlen) {
		int nextPos = next[nowPos][ti[tPos] - 'a'];
		if (nextPos == -1) {
			ans += (LLONG)(slen - nowPos);
			nowPos = 0;
		}
		else {
			tPos++;
			nextPos++;
			if (nextPos > (slen - 1)) {
				ans += slen - nowPos;
				nextPos = 0;
			}
			else {
				ans += nextPos - nowPos;
			}
			nowPos = nextPos;
		}
	}
	printf("%lld\n", ans);
}