#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 1000000000000000000/ans) {
			cout << -1 << endl;
			return 0;
		}
		else ans *= a[i];
	} 
	cout << ans << endl;
}