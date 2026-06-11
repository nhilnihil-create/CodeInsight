#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, x; cin >> n >> x;
	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	int ans = 1;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		int now = prev + l[i];
		if (now <= x) ans++;
		prev = now;
	}
	cout << ans << endl;
	return 0;
}