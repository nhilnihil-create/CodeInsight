#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

long long int getGcd(long long int m, long long int n) {
	if (n == 0) return m;
	return getGcd(n, m % n);
}

int main() {
	long long int n, m;
	cin >> n >> m;
	long long int a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int twonum = 0;
	while (a[0] % 2 == 0) {
		twonum++;
		a[0] /= 2;
	}
	bool ok = true;
	for (int i = 1; i < n; i++) {
		long long int tmp = 0;
		while (a[i] % 2 == 0) {
			tmp++;
			a[i] /= 2;
		}
		if (tmp != twonum) {
			ok = false;
			break;
		}
	}
	if (ok) {
		long long int gcd = a[0];
		long long int tmp = a[0];
		for (int i = 1; i < n; i++) {
			gcd = getGcd(tmp, a[i]);
			tmp = (tmp * a[i]) / gcd;
		}
		tmp *= (1 << (twonum - 1));
		// cout << tmp << endl;
		cout << (m / tmp) / 2 + (m / tmp) % 2 << endl;
	} else {
		cout << 0 << endl;
	}
}