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
	ll n, a, b;
	cin >> n >> a >> b;
	ll s = a + b;
	cout << (n / s) * a + min(a, n % s) << endl;

	return 0;
}
