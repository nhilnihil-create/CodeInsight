#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

//int main() {
//	long long a, b, x;
//	cin >> a >> b >> x;
//	long long ans = 0;
//	long long d = 10;
//
//	for (int i = 0;i < 10;i++) {
//		if (x < a * (long long)pow(10, i) + b * ((long long)i + (long long)1)) {
//			d = i;
//			break;
//		}
//	}
//
//	if (d == 0) {
//		cout << 0 << endl;
//		return 0;
//	}
//
//	x -= b * d;
//	ans = x - b*d / a;
//	if (ans > 1000000000) {
//		ans = 1000000000;
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}

int main() {
	int n;
	cin >> n;
	vector<int> x(n + 1);
	vector<int> y(n + 1);
	int j[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i];
	}

	long double distance = 0;
	double cnt = 0;

	do {
		for (int i = 0; i < n - 1; i++) {
			distance += sqrt(pow(x[j[i]] - x[j[i + 1]], 2) + pow(y[j[i]] - y[j[i + 1]], 2));
		}
		cnt++;
	} while (next_permutation(j, j + n));

	distance /= cnt;

	printf("%.10llf", distance);

	return 0;
}
