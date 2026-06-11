#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;

signed main() {
	// ios::sync_with_stdio(false);
	ll a, c;
	double b;
	cin >> a >> b;
	c = b * 100 + 0.1;
	cout << (ll)(a * c / 100) << '\n';
	return 0;
}