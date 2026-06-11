#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<pair<double, double>>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
	}
	// 入力したベクトルのソート
	sort(v.begin(), v.end());

	int cnt = 1;
	double dist = 0;
	do {
		// ベクトルの順列の数だけ繰り返し
		for (int i = 0;i < n - 1;i++) {
			dist += sqrt(pow((v[i + 1].first - v[i].first), 2.0) + pow((v[i + 1].second - v[i].second), 2.0));
		}
	} while (next_permutation(v.begin(), v.end()));
	for (int i = 1;i <= n;i++) {
		cnt *= i;
	}
	cout << fixed << setprecision(10) << dist/cnt << endl;
}
