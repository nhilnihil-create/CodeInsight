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

ll f(ll n) {
	if (n == 1) {
		return 1;
	}
	return 2 * f(n / 2) + 1;
}

int main() {
	ll n;
	cin >> n;
	cout << f(n);

	return 0;
}
