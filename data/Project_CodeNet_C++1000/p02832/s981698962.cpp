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

int main() {
	long long n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	int cnt = 1;
	int ans = 0;
	int flag = 0;
	for (int i = 0;i < n;i++) {
		if (a[i] == cnt) {
			cnt++;
		}
		else {
			ans++;
		}
	}

	if (cnt == 1) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}
