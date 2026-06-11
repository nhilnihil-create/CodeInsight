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
	ll ret = 0;
	ll sum = 0;
	ll num = 0;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		sum += a * b;
		num += b;
	}
	cout << ((sum - 1) / 9 + (num - 1)) << endl;
	return 0;
}
