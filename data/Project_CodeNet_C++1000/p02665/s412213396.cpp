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
long long a[100010];
int main() {
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		cin >> a[i];
		sum += a[i];
	}
	long long ans = 1, ans1 = 0;
	for (int i = 0; i < n + 1; i++) {
		ans -= a[i];
		if (i != n) {
			if (ans <= 0) {
				cout << "-1" << endl;
				return 0;
			}
		}
		else {
			if (ans < 0) {
				cout << "-1" << endl;
				return 0;
			}
		}
		ans *= 2;
		sum -= a[i];
		ans = min(ans, sum);
		ans1 += ans;
	}
	cout << ans1 + 1 << endl;
}
