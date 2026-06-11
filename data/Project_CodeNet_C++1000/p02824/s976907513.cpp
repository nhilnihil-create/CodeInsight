
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

static void exec()
{
	int N;
	getint(N);
	LLONG M;
	getint(M);
	int V, P;
	getint(V, P);

	std::vector<LLONG> ai(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}
	std::sort(ai.begin(), ai.end(), std::greater<LLONG>());
	
	int ans = 0;
	int start = P;
	int end = N - 1;
	while (1) {
		bool lower = false;
		int idx = (start + end) / 2;

		if (ai[idx] + M < ai[P - 1]) {
			lower = true;
		}
		else {
			LLONG pt = 0;
			for (int i = P - 1; i < idx; i++) {
				pt += (ai[idx] + M) - ai[i];
			}
			pt += M * (P - 1) + M * (N - idx);
			if (pt < (M * V)) {
				lower = true;
			}
		}

		if ((end - start) <= 1) {
			if (lower) {
				ans = idx;
			}
			else {
				if (idx != end) {
					idx = end;
					LLONG pt = 0;
					if (ai[idx] + M < ai[P - 1]) {
						lower = true;
					}
					else {
						for (int i = P - 1; i < idx; i++) {
							pt += (ai[idx] + M) - ai[i];
						}
						pt += M * (P - 1) + M * (N - idx);
						if (pt < (M * V)) {
							lower = true;
						}
					}
					if (lower) ans = idx;
					else ans = idx + 1;
				}
				else {
					ans = idx + 1;
				}
			}
			break;
		}

		if (lower) {
			end = idx;
		}
		else {
			start = idx;
		}
	}
	printf("%d\n", ans);
}
