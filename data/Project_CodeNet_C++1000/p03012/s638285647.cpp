#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> w(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		sum += w[i];
	}
	int ans = 100000000;
	for (int i = 1; i < n; i++) {
		int left = 0;
		int right = 0;
		for (int j = 0; j < i; j++) {
			left += w[j];
		}
		right = sum - left;
		ans = min(ans, abs(left - right));
	}
	cout << ans << endl;
	return 0;
}