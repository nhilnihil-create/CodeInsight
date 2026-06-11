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

int main() {
	ll a, b, v, w, t;
	cin >> a >> v >> b >> w >> t;

	ll dv = v - w;
	ll d = abs(b - a);
	if (dv <= 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (t * dv >= d) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
