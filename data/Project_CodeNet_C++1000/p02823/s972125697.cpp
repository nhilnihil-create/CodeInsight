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

ll n, a, b;

ll f(ll l, ll r) {
	ll d = r - l;
	if (d & 1) {
		ll s1 = l + f(1, r - l);
		ll s2 = n - r + 1 + f(l + n - r + 1, n);
		return min(s1, s2);
	} else {
		return (r - l) / 2;
	}
}

int main() {
	cin >> n >> a >> b;
	cout << f(a, b) << endl;
	return 0;
}
