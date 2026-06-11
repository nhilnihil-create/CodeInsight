#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	double ans;
	double prev = (double)v[0];
	for (int i = 1; i < n; i++) {
		ans = (double)(prev + v[i]) / 2;
		prev = ans;
	}
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}