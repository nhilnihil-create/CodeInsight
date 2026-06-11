#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>w(n);
	for (int i = 0; i < n; i++)cin >> w.at(i);
	ll l = 0;
	ll r = 0;
	for (int i = 0; i < n; i++)r += w.at(i);
	ll ans = r;
	for (int i = 0; i < n; i++) {
		l += w.at(i);
		r -= w.at(i);
		ans = min(ans, abs(r - l));
	}
	cout << ans << endl;
}