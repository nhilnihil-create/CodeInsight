#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int k, n;
	int ans = 0;
	cin >> k >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep (i, n - 1) ans = max(ans, a[i + 1] - a[i]);
	ans = max(ans, (k - a[n - 1]) + a[0]);
	cout << k - ans << endl;
	return 0;
}
