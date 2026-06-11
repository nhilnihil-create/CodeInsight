#include <iostream>
#include <string>
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
int main() {
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int b[3];
		b[0] = a[i - 1];
		b[1] = a[i];
		b[2] = a[i + 1];
		sort(b, b + 3);
		if (a[i] == b[1]) {
			ans++;
		}
	}
	cout << ans << endl;
}
