#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

int k;

#define MAXN 20

int ten[MAXN];

ll getnum(vector<int> v) {
	ll ret = 0;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		ret *= 10;
		ret += v[i];
	}
	return ret;
}

ll getnext(ll num) {
	num++;
	while (true) {
		vector<int> v;
		ll tnum = num;
		while (tnum) {
			v.push_back(tnum % 10);
			tnum /= 10;
		}
		int n = v.size();
		bool ok = true;
		for (int i = n - 1; i > 0; i--) {
			if (abs(v[i] - v[i - 1]) <= 1) {
				continue;
			}
			ok = false;
			num += ten[i - 1];
			break;
		}
		if (ok) {
			return getnum(v);
		}
	}
}

int main() {
	int curt = 1;
	for (int i = 0; i < MAXN; i++) {
		ten[i] = curt;
		curt *= 10;
	}


	cin >> k;
	ll cur = 1;
	int pos = 0;
	while (true) {
		pos++;
		if (pos == k) {
			cout << cur << endl;
			return 0;
		}
		//cout << cur << endl;
		cur = getnext(cur);
	}
	return 0;
}
