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
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	vector<int> s(n);
	for (int i = 0;i < n;i++) {
		cin >> d[i];
		if (i == 0)s[i] = d[i];
		else s[i] = s[i - 1] + d[i];
	}

	long long ans = 0;
	for (int i = 0;i < n;i++) {
		ans += d[i] * (s[n - 1] - s[i]);
	}

	cout << ans << endl;

	return 0;
}
