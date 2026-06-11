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

#define MAXN (1 << 20)

int a[MAXN];

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		 cin >> a[i];
		 sum += a[i];
	}
	ll best = 2 * sum;
	ll curs = 0;
	for (int i = 0; i <= n; i++) {
		ll cur = llabs(2 * curs - sum);
		if (cur < best) {
			best = cur;
		}
		if (i < n) {
			curs += a[i];
		}
	}
	cout << best << endl;

	return 0;
}
