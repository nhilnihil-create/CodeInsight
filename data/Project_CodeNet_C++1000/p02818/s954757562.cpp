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
	ll a, b, k;
	cin >> a >> b >> k;
	if (a >= k) {
		cout << a - k << " " << b << endl;
	} else if (a + b >= k) {
		cout << "0 " << a + b - k << endl;
	} else {
		cout << "0 0" << endl;
	}
	return 0;
}
