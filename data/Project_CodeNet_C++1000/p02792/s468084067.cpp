#include <assert.h>
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

int n;

int mem[10][10];

pair<int, int> dig(int k) {
	int d1 = k % 10;
	int d2;
	while (k) {
		d2 = k % 10;
		k /= 10;
	}
	return make_pair(d2, d1);
}


int g(pair<int, int> p) {
	swap(p.first, p.second);
	int & ret = mem[p.first][p.second];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 1; i <= n; i++) {
		pair<int, int> cur = dig(i);
		if (cur == p) {
			ret++;
		}
	}
	return ret;

}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> n;
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += g(dig(i));
	}
	cout << ret << endl;
	return 0;
}
