#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 20)

int mem[MAXN][2];
int a[MAXN];

int f(int pos, int k) {
	if (pos < 0) {
		return k;
	}
	int & ret = mem[pos][k];
	if (ret != -1) {
		return ret;
	}
	int cur = a[pos] + k;
	int sol1 = f(pos - 1, 0) + cur;
	int sol2 = f(pos - 1, 1) + (10 - cur);
	ret = min(sol1, sol2);

	return ret;
}

int main() {
	int n;
	memset(mem, -1, sizeof(mem));
	string s;
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	cout << f(n - 1, 0) << endl;
	return 0;
}
