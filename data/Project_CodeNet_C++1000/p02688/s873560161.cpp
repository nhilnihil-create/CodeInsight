#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> d(k);
	vector<vector<int>> a(k, vector<int>(n));
	vector<int> cnt(n + 1);
	int ans = 0;

	for (int i = 0;i < k;i++) {
		cin >> d[i];
		for (int j = 0;j < d[i];j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}

	for (int i = 1;i <= n;i++) {
		if (cnt[i] == 0) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}