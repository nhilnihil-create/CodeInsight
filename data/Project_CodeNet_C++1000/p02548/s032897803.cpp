#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (n - 1) / i;
	}
	cout << ans << endl;
	return 0;
}
