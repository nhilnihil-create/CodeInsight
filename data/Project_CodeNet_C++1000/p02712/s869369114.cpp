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

typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	int n;
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (!(i % 3 == 0) && !(i % 5 == 0)) {
			ans += i;
		}
	}
	cout << ans << endl;
	
	return 0;
}
