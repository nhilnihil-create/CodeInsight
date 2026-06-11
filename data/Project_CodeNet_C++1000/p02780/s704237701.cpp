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
	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	for(int i = 0;i < n;i++) {
		cin >> p[i];
	}

	double sum = 0;
	for (int i = 0;i < k;i++) {
		sum += p[i];
	}

	double max = sum;
	
	for (int i = 0;i < n - k;i++) {
		sum += p[i + k];
		sum -= p[i];
		if (max < sum) max = sum;
	}
	double ans = (max + (double)k) / 2;
	printf("%lf", ans);
	return 0;
}