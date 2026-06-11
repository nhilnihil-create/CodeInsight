
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

static void diverta2019PC2C();

#if 1
int main()
{
	diverta2019PC2C();
	fflush(stdout);
	return 0;
}
#endif

static void diverta2019PC2C()
{
	int N;
	getint(N);

	std::deque<int> pque, mque;
	int absMax = 0, maxVal = 0;
	for (int i = 0; i < N; i++) {
		int a;
		getint(a);
		if (a >= 0) {
			pque.insert(std::lower_bound(pque.begin(), pque.end(), a), a);
		}
		else {
			mque.insert(std::lower_bound(mque.begin(), mque.end(), a), a);
		}
	}

	std::vector<std::pair<int, int>> proc;
	while ((mque.size() + pque.size()) > 1) {
		int first = 0, second = 0;
		if (!mque.empty() && pque.empty()) {
			if (mque.size() > 2) {
				first = mque.back();
				mque.pop_back();
				second = mque.back();
				mque.pop_back();
			}
			else {
				second = mque.back();
				mque.pop_back();
				first = mque.back();
				mque.pop_back();
			}
		}
		else if (mque.empty() && !pque.empty()) {
			if (pque.size() > 2) {
				second = pque.front();
				pque.pop_front();
				first = pque.front();
				pque.pop_front();
			}
			else {
				first = pque.front();
				pque.pop_front();
				second = pque.front();
				pque.pop_front();
			}
		}
		else if (!mque.empty() && !pque.empty()) {
			if (pque.size() == 1) {
				first = mque.front();
				mque.pop_front();
				second = pque.front();
				pque.pop_front();
			}
			else {
				second = mque.front();
				mque.pop_front();
				first = pque.front();
				pque.pop_front();
			}
		}
		proc.push_back(std::pair<int, int>(second, first));
		int newVal = second - first;
		if (newVal >= 0) {
			pque.insert(std::lower_bound(pque.begin(), pque.end(), newVal), newVal);
		}
		else {
			mque.insert(std::lower_bound(mque.begin(), mque.end(), newVal), newVal);
		}
	}
	int ans = (!pque.empty() ? pque.front() : mque.front());
	printf("%d\n", ans);
	for (auto it = proc.begin(); it != proc.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}
}
