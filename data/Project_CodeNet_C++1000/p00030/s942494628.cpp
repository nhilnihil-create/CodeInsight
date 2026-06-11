#define _USE_MATH_DEFINES
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <string.h>
#include <utility>
#include <cstdio>
#include <set>
#include <map>
#include <assert.h>
using namespace std;

#define INF (1 << 20)
#define EPS (1e-10)
#define EQ(a,b) (fabs((a)-(b)) < EPS)

#define ll long long
#define LL long long

int flg[10];

int dfs(int n, int s) {
	int ret = 0;
	if (n == 0) return s == 0;
	for (int i = 0; i < 10; ++i) {
		if (flg[i]) continue;
		flg[i]++;
		ret += dfs(n-1, s-i);
		flg[i]--;
	}
	return ret;
}

int main() {
	int n, s;
	while (cin >> n >> s) {
		if (n == 0) break;
		int res = dfs(n, s);
		while (n != 0) res /= n--;
		cout << res << endl;
	}
	return 0;
}