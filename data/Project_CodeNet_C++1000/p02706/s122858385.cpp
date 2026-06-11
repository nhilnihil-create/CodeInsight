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
	int n, m;
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		sum += t;
	}
	n -= sum;
	if (n < 0) {
		cout << -1;
	} else {
		cout << n << endl;
	}

	return 0;
}
