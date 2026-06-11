#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
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
static const LLONG MOD_NUM = 1000000007;//998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template<class _T> static void getint(_T& a) {
	if (sizeof(_T) > sizeof(int)) {
		scanf("%lld", &a);
	}
	else {
		scanf("%d", &a);
	}
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

class data {
public:
	int a, b, c, d;
};

static int dfs(std::vector<int> An, int M, int N, std::vector<data>& qi)
{
	int val = 0;
	if (An.size() == N) {
		int Q = qi.size();
		for (int q = 0; q < Q; q++) {
			if (An[qi[q].b] - An[qi[q].a] == qi[q].c) {
				val += qi[q].d;
			}
		}
	}
	else {
		int idx = An.size();
		int last = 1;
		if (idx) {
			last = *An.rbegin();
		}
		An.push_back(0);
		for (int num = last; num <= M; num++) {
			An[idx] = num;
			val = std::max(val, dfs(An, M, N, qi));
		}
	}
	return val;
}


static void exec()
{
	int N, M, Q;
	get(N, M, Q);

	std::vector<data> qi(Q);
	for (int i = 0; i < Q; i++) {
		get(qi[i].a, qi[i].b); qi[i].a--; qi[i].b--;
		get(qi[i].c, qi[i].d);
	}

	printf("%d\n", dfs(std::vector<int>(), M, N, qi));
}
