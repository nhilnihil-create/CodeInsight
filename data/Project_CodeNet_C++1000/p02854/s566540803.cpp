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
long long sum[200020];
long long a[200020];
int main() {
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[i + 1] += a[i];
		sum[i + 1] += sum[i];
	}
	long long co = 0;
	long long ans = 1000000000007;
	for (int j = 0; j <= n; j++) {
		long long m = abs(sum[n] - sum[j] - co);
		if (ans > m) {
			ans = m;
		}
		co += a[j];
	}
	cout << ans << endl;
}