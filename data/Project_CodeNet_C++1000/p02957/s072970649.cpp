#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, b; cin >> a >> b;
	if (b < a) swap(a, b);
	if ((b - a) % 2 != 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << (a + b) / 2 << endl;
	return 0;
}