#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int A, B, M, * a, * b, x, y, c, minA = pow(10, 5), minB = pow(10, 5), p = 3 * pow(10, 5), tmp = 0;

	cin >> A >> B >> M;;

	a = new int[A];
	b = new int[B];

	for (int i = 0; i < A; i++) {
		cin >> a[i];
		if (minA > a[i]) { minA = a[i]; }
	}

	for (int i = 0; i < B; i++) {
		cin >> b[i];
		if (minB > b[i]) { minB = b[i]; }
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> c;
		tmp = a[x -1] + b[y -1] - c;
		if (p > tmp) {
			p = tmp;
		}
	}

	if (minA + minB < p) { p = minA + minB; }

	cout << p;

	return 0;
}