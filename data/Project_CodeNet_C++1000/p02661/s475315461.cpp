#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	int n;
	ll ans;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i, n)cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (n % 2 == 0) {
		ans = b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1;
	}
	else {
		ans = b[n / 2] - a[n / 2] + 1;
	}
	cout << ans << endl;
	return 0;
}