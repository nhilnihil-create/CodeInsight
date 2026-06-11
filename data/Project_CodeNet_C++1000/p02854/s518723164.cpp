#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
	
	int n; cin >> n;
	vector<ll> a(n + 1, 0);
	vector<ll> accum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		accum[i] += a[i];
		accum[i] += accum[i - 1];
	}
	ll thresholdValue = 9223372036854775807LL;
	for (int i = 1; i <= n; i++) {
		ll tmp = abs(accum[i] - (accum[n] - accum[i]));
		chmin(thresholdValue, tmp);
	}
	cout << thresholdValue << endl;
	return 0;
}