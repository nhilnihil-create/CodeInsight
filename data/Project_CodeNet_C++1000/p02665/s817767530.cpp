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

ll a[MAXN];
ll s[MAXN];
int n;

ll check(int l, ll b) {
	if (l > n) {
		if (b == 0) {
			return 0;
		} else {
			return -1;
		}
	}
	if (b < a[l]) {
		return -1;
	}
	ll nnext = check(l + 1, min(2 * (b - a[l]), s[l + 1]));
	if (nnext >= 0) {
		return b + nnext; 
	} else {
		return -1;
	}
}


int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 0; i--) {
		s[i] = s[i + 1] + a[i];
	}
	cout << check(0, 1) << endl;
	return 0;
}
