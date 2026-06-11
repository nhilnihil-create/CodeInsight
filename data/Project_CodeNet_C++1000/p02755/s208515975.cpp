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

#define MMAX 100000

int f(int x, int m) {
	return (x * m) / 100;
}

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= MMAX; i++) {
		if (f(i, 8) == a && f(i, 10) == b) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;

	return 0;
}
