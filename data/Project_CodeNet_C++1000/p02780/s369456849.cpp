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

int n, k;
vector<int> a;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	ll sum = 0;
	ll mmax = 0;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	mmax = sum;
	for (int i = k; i < n; i++) {
		sum += a[i];
		sum -= a[i - k];
		mmax = max(mmax, sum);
	}
	ld ans = (ld) (mmax) / (2.0 * k) + 0.5;
	printf("%.9Lf\n", k * ans);
	return 0;
}
