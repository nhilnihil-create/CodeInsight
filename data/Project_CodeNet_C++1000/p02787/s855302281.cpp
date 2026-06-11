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

#define MAXN (1 << 16)
#define INF (1 << 30)

int mem[MAXN];
int a[MAXN], b[MAXN];
int h, n;

int f(int k) {
	if (k <= 0) {
		return 0;
	}
	int & ret = mem[k];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int i = 0; i < n; i++) {
		int cur = f(k - a[i]) + b[i];
		ret = min(ret, cur);
	}
	return ret;
}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> h >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	cout << f(h) << endl;
	return 0;
}
