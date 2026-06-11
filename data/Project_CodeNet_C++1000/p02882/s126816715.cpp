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

#define PI ((ld)3.141592653589793238) 

using namespace std;

int main() {
	ld a, b, x;
	cin >> a >> b >> x;
	x /= a;
	if (x >= 0.5 * a * b) {
		printf("%.10Lf\n",90 - (180 / PI) * atan2l(a * a, 2 * (a * b - x)));
	} else {
		printf("%.10Lf\n", 90 - (180 / PI) * atan2l(2 * x, b * b));
	}
	return 0;
}
