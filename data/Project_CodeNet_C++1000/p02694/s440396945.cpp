#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll x; cin >> x;
	int r = 1;
	int y = 0;
	ll m = 100;
	while (m < x) {
		m = m + m * r / 100;
		y++;
	}
	cout << y << endl;
	return 0;
}