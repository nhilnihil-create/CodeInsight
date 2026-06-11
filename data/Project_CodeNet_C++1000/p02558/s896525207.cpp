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
#include <atcoder/all>
using namespace atcoder;
using namespace std;
int main() {
	int n;
	cin >> n;
	dsu d(n);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int b, l, r;
		cin >> b >> l >> r;
		if (b == 0) {
			d.merge(l, r);
	    }
		else {
			if (d.same(l, r)) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
	}
}
