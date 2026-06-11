
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
	int X, Y, A, B, C;
	getint(X, Y);
	getint(A, B, C);

	std::vector<LLONG> pi(A);
	for (int i = 0; i < A; i++) {
		getint(pi[i]);
	}
	std::vector<LLONG> qi(B);
	for (int i = 0; i < B; i++) {
		getint(qi[i]);
	}
	std::vector<LLONG> ri(C);
	for (int i = 0; i < C; i++) {
		getint(ri[i]);
	}

	std::sort(pi.begin(), pi.end(), std::greater<LLONG>());
	std::sort(qi.begin(), qi.end(), std::greater<LLONG>());
	std::sort(ri.begin(), ri.end(), std::greater<LLONG>());

	std::priority_queue<LLONG, std::vector<LLONG>, std::greater<LLONG>> rque, gque;
	for (int i = 0; i < X; i++) {
		rque.push(pi[i]);
	}
	for (int i = 0; i < Y; i++) {
		gque.push(qi[i]);
	}

	LLONG red, green;
	for (int i = 0; i < C; i++) {
		red = rque.top();
		green = gque.top();
		if (red > green) {
			if (green < ri[i]) {
				gque.pop();
				gque.push(ri[i]);
			}
		}
		else {
			if (red < ri[i]) {
				rque.pop();
				rque.push(ri[i]);
			}
		}
	}

	LLONG sum = 0;
	while (!rque.empty()) {
		sum += rque.top();
		rque.pop();
	}
	while (!gque.empty()) {
		sum += gque.top();
		gque.pop();
	}
	printf("%lld\n", sum);
}
