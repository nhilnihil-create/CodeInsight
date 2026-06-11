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
	ll n;
	cin >> n;
	ll ret = n + n;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll n1 = n / i;
			ll n2 = i;
			ll cur = n1 + n2 - 2;
			ret = min(ret, cur);
		}
	}
	cout << ret << endl;
	return 0;
}
