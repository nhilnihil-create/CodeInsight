#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, a, b, i, j, k, m;
pair<double, double> str[105];
bool cmp(const pair<double, double> a, const pair<double, double> b) {
	return atan2(a.second, a.first) < atan2(b.second, b.first);
}
int main() {
	double x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> str[i].first >> str[i].second;
	}
	sort(str, str + n, cmp);
	double ans = 0;
	for (i = 0; i < n; i++) {
		x = str[i].first; y = str[i].second;
		ans = max(ans, x * x + y * y);
		for (j = (i + 1) % n; j != i; j = (j + 1) % n) {
			x += str[j].first; y += str[j].second;
			ans = max(ans, x * x + y * y);
		}
	}
	printf("%.10lf", sqrt(ans));
}