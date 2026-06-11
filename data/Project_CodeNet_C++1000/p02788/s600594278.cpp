#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, d, a;
	cin >> n >> d >> a;
	vector<pair<long long, long long>> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
		x[i].second = (x[i].second + a - 1) / a;
	}
	sort(x.begin(), x.end());
	long long ans = 0;
	vector<long long> v(n+1, 0);
	for (int i = 0, j = 0; i < n; i++) {
		if (v[i] < x[i].second) {
			long long b = x[i].second - v[i];
			ans += b;
			v[i] += b;
			while (j < n && x[j].first <= x[i].first + 2*d) j++;
			v[j] -= b;
		}
		v[i+1] += v[i];
	}
	cout << ans << endl;
	return 0;
}