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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	long long ans = 0;
	map<int, int> m{};
	for (int i = 0;i < n;i++) {
		if (i - a[i] > 0)ans += m[i - a[i] + 1];
		m[a[i] + i + 1]++;
	}

	cout << ans << endl;
	return 0;
}
