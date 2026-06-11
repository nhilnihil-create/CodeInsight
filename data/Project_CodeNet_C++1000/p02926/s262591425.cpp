#include <bits/stdc++.h>
using namespace std;

pair<long, long> x[111];
long s[111], t[111];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x[i] = { a,b };
		if (!a && !b) i--, n--;
	}
	sort(x, x + n, [](auto a, auto b) {
		if (a.second >= 0 && b.second <= 0 && (a.second || a.first > 0) && (b.second || b.first < 0))
			return true;
		if (b.second >= 0 && a.second <= 0 && (b.second || b.first > 0) && (a.second || a.first < 0))
			return false;
		return a.first*b.second > a.second*b.first;
	});
	for (int i = 0; i < n; i++)
		s[i + 1] = s[i] + x[i].first, t[i + 1] = t[i] + x[i].second;
	long m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			auto a = s[j] - s[i], b = t[j] - t[i];
			m = max(m, a*a + b * b);
			a = s[n] - a, b = t[n] - b;
			m = max(m, a*a + b * b);
		}
	}
	cout.precision(18);
	cout << sqrt(m) << endl;
	return 0;
}
