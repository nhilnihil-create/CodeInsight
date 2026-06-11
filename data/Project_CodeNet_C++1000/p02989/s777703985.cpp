#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	ll left = d[n / 2 - 1];
	ll right = d[n / 2];
	cout << max(0LL, right - left) << endl;
	return 0;
}