#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long gcd(long long a, long long b) {
	if (a % b == 0) {
		return (b);
	}
	else {
		return (gcd(b, a % b));
	}
}

long long a[100010];
int main() {
	long long n, m;
	long long co1 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		long long a1 = a[i];
		long long co = 0;
		for (;;) {
			if (a[i] % 2 == 0) {
				a[i] /= 2;
				co++;
			}
			else {
				break;
			}
		}
		if (i != 0) {
			if (co1 != co) {
				cout << "0" << endl;
				return 0;
			}
		}
		co1 = co;
		a[i] = a1 / 2;
	}
	long long lcm = 1;
	for (int j = 0; j < n; j++) {
		lcm = a[j] / gcd(lcm, a[j]) * lcm;
		if (lcm > m) {
			cout << "0" << endl;
			return 0;
		}
	}
	long long ans = 0;
	if (lcm <= m) {
		m -= lcm;
		ans++;
		ans += m / (lcm * 2);
	}
	cout << ans << endl;
	return 0;
}
