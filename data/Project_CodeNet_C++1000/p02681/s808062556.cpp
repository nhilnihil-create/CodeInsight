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

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
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
	std::string s, t;
	getval(s, t);

	int len = s.length();
	bool equal = true;
	for (int i = 0; i < len; i++) {
		if (s[i] != t[i]) equal = false;
	}
	printf("%s\n", (equal ? "Yes" : "No"));
}
