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
	vector<int> x(n);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> x[i];
		sum += x[i];
	}
	sum = (double)sum / n + 0.5;

	long long ans = 0;

	for (int i = 0;i < n;i++) {
		ans += pow(x[i] - sum, 2);
	}
	cout << ans << endl;
	return 0;
}