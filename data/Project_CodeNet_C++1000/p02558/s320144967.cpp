#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int par[200020];

int root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = root(par[x]);
	}
}
int main() {
	int n, q, p, a, b;
	int x, y;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
	for (int j = 0; j < q; j++) {
		cin >> p >> a >> b;
		if (p == 0) {
			x = root(a);
			y = root(b);
			if (x != y) {
				par[x] = y;
			}
		}
		else {
			if (root(a) == root(b)) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
	}
	return 0;
}
