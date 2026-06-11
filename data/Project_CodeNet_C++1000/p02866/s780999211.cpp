#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> C(n);
	int md = 0;
	rep(i, n) {
		int x;
		cin >> x;
		C[x]++;
		if (i == 0 && x != 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (C[0] != 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < C[i]; j++) {
			ans *= C[i-1];
			ans %= 998244353;
		}
	}
	cout << ans << endl;
}