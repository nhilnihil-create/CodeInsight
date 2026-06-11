#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

#define LL long long

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, q;
LL *d;
LL ni;
LL xi, mi;
LL dSum = 0;

LL query(LL ni, LL xi, LL mi) {
	LL loopN = (ni - 1) / (LL)(n);
	dSum = 0;
	LL zCount = 0;
	for (int i = 0; i < n; ++i) {
		dSum += (d[i] % mi);
		if (d[i] % mi == (LL)(0)) {
			zCount += 1;
			dSum += mi;
		}
	}
	// cout << "dSum = " << dSum << endl;
	LL total = loopN * dSum;
	for (int i = 0; i < int((ni - 1) % (LL)(n)); ++i) {
		total += (d[i] % mi);
		if (d[i] % mi == (LL)(0)) {
			// dSum += mi;
			total += mi;
		}
	}
	// cout << "total = " << total << endl;
	LL res = ni - 1;
	xi = xi % mi;
	// how many times we cross mi, from xi to xi + total?
	res -= ((xi + total) / mi);
	return res;

}
int main() {
	cin >> n >> q;
	d = new LL[n];
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		dSum += d[i];
	}
	// prepare();
	for (int i = 0; i < q; ++i) {
		cin >> ni;
		cin >> xi >> mi;

		cout << query(ni, xi, mi) << endl;
	}
	return 0;
}