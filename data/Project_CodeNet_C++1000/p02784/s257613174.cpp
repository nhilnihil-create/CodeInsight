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
	ll h, n;
	ll s = 0;
	cin >> h >> n;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		s += t;
	}
	if (h - s <= 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
