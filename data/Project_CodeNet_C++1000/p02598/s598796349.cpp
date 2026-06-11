#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ng = 0, ok = 1e9;
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		int cut = 0;
		rep (i, n) cut += (a[i] - 1) / mid;
		if (cut > k) ng = mid;
		else ok = mid;
	}
	cout << ok << endl;
	return 0;
}
