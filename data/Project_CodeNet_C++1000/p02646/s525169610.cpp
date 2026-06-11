#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, v, b, w, t; cin >> a >> v >> b >> w >> t;
	string ans = "NO";
	ll dist = abs(a - b);
	if (dist <= (v - w) * t) {
		ans = "YES";
	}
	cout << ans << endl;
	return 0;
}