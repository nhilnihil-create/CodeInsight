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
long long a[100010], co[100010] = { 0 };
int main() {
#define int long long
	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			m = a[i];
		}
		co[a[i]]++;
	}
	if (a[0] != 0) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			cout << "0" << endl;
			return 0;
		}
	}
	sort(a, a + n);
	long long ans = 1;
	for (int i = 1; i < m + 1; i++) {
		long long co1 = co[i - 1];
		for (int j = 1; j < co[i]; j++) {
			co[i - 1] = co[i - 1] * co1 % 998244353;
		}
		ans = ans * co[i - 1] % 998244353;
	}
	cout << ans << endl;
	return 0;
}
