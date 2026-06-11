#include <bit>
#include <bitset>
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

vector<vector<pair<int, int> > > a;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int> > cur;
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int v, b;
			cin >> v >> b;
			v--;
			cur.push_back(make_pair(v, b));
		}
		a.push_back(cur);

	}

	int ret = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (int j = 0; j < a[i].size(); j++) {
					int val = 0;
					if (mask & (1 << a[i][j].first)) {
						val = 1;
					} 
					if (val != a[i][j].second) {
						ok = false;
					}
				}
			}
		}
		if (ok) {
			ret = max(ret, __builtin_popcount(mask));
		}
	}
	cout << ret << endl;
	return 0;
}
