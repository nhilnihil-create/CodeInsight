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

typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN 64

int n, m;
int q;
int a[MAXN][4];
int ret = 0;

set<pair<pair<int, int>, vector<int> > > s;

int bitcnt(int mask) {
	int ret = 0;
	while (mask) {
		mask &= mask - 1;
		ret++;
	}
	return ret;
}

int check(vector<int> cur) {
	reverse(cur.begin(), cur.end());
/*	for (int i = 0; i < cur.size(); i++) {
		cout << cur[i] << " ";
	}
	cout << endl;
*/	int curbest = 0;
	for (int i = 0; i < q; i++) {
		if (max(a[i][0], a[i][1]) > cur.size()) {
			continue;
		}
		if (cur[a[i][1] - 1] - cur[a[i][0] - 1] == a[i][2]) {
			curbest += a[i][3];
		}
	}
	return curbest;
}

void gen(int n, int m, vector<int> & v) {
	pair<pair<int, int>, vector<int> > p = make_pair(make_pair(n, m), v);
	if (s.count(p)) {
		return;
	}
	s.insert(p);
	if (m == 0) {
		return;
	}
	if (n == 0) {
		ret = max(ret, check(v));
		return;
	}
	v.push_back(m);
	gen(n - 1, m, v);
	v.pop_back();
	gen(n, m - 1, v);
}

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}

	ret = 0;
	vector<int> v;
	gen(n, m, v);
	cout << ret << endl;

	return 0;
}
