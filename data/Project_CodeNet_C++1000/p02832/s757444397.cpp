#include <bit>
#include <bitset>
#include <assert.h>
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

#define MAXN (1 << 20)

int a[MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == cur + 1) {
			cur++;
		}
	}
	if (cur) {
		cout << n - cur;
	} else {
		cout << - 1;
	}
	cout << endl;

	return 0;
}
