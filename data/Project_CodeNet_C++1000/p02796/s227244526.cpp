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

#define INF (1 << 30)

vector<pair<int, int> > v;



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		v.push_back(make_pair(x - l, x + l));
	}
	sort(v.begin(), v.end());
	int cur = -INF;
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= cur) {
			ret++;
			cur = v[i].second;
		} else if (v[i].second < cur) {
			cur = v[i].second;
		}
	}
	cout << ret << endl;
	return 0;
}
