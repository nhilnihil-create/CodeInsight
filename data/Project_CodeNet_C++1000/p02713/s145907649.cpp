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

int gcd(int a, int b) {
	if (a < b) {
		return gcd(b, a);
	}
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int gcd2(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main() {
	int k;
	int ans = 0;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++) {
				ans += gcd(gcd(i, j), l);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
