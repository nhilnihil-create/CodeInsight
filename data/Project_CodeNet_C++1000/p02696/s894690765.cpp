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


ll a, b, n;

int main() {
	cin >> a >> b >> n;
	
	n = min(n, b - 1);
	cout << (ll)(a * n / b);

	return 0;
}
