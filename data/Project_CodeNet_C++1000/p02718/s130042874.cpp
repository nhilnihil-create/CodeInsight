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

#define MAXN (1 << 10)

int a[MAXN];

int main() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (4 * m * a[i] >= sum) {
			cnt++;
		}
	}
	if (cnt >= m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
