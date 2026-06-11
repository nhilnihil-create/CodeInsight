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
long long a[200020];
long long sum[200020];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			sum[i] = a[i] + sum[i - 1];
		}
		else {
			sum[i] = a[i];
		}
	}
	long long co = 0;
	long long  min = 1000000000000000007;
	for (int j = 0; j < n; j++) {
		co += a[j];
		long long  k = sum[n - 1] - sum[j];
		long long ans = abs(k - co);
		if (min > ans) {
			min = ans;
		}
	}
	cout << min << endl;
	return 0;
}