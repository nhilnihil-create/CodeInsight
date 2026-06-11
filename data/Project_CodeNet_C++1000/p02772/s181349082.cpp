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

bool good(int k) {
	if (k & 1) {
		return true;
	}
	return ((k % 3 == 0) || (k % 5 == 0));
}

int main() {
	bool ok = true;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (!good(t)) {
			ok = false;
		}
	}
	if (ok) {
		cout << "APPROVED" << endl;
	} else {
		cout << "DENIED" << endl;
	}
	return 0;
}
