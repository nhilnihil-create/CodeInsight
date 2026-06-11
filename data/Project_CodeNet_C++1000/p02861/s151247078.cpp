#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = i;
	}
	vector<double> t;
	do {
		double tmp = 0;
		for (int i = 1; i < n; i++) {
			tmp += (double)sqrt((x[c[i]] - x[c[i - 1]]) * (x[c[i]] - x[c[i - 1]]) + (y[c[i]] - y[c[i - 1]]) * (y[c[i]] - y[c[i - 1]]));
		}
		t.push_back(tmp);
	} while (next_permutation(c.begin(), c.end()));
	double ans = 0;
	for (int i = 0; i < t.size(); i++) {
		ans += t[i];
	}
	cout << fixed << setprecision(11) << ans / t.size() << endl;
}