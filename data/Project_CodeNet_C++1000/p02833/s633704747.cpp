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

ll n;

int main() {
	cin >> n;
	if (n & 1) {
		cout << 0 << endl;
		return 0;
	}
	
	ll ret = 0;
	ll five = 5;
	ll corr = 0;
	while (five <= n) {
		ret += n / five;
		if (n >= five) {
			corr += (n - five) / (2 * five) + 1;	
		}
		five *= 5;
	}
	//cerr << ret << " " << corr << endl;
	cout << ret - corr << endl;
	return 0;
}
