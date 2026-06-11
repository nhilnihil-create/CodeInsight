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
/*
注意!! #include <atcoder/all>
*/
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	dsu unionfind(n);
	for (int i = 0; i < q; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			unionfind.merge(u, v);
		}
		else {
			if (unionfind.same(u, v)) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}

	}
}
