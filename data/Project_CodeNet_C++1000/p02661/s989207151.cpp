#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int h = n / 2;
	if (n % 2 == 1) {
		ans = b[h] - a[h] + 1;
	}
	else {
		ans = b[h] + b[h - 1] - a[h] - a[h - 1];
		ans++;
	}
	cout << ans << endl;
	return 0;
}
