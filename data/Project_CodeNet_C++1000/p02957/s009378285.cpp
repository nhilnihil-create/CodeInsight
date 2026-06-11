#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, b; cin >> a >> b;
	ll tmp = a + b;
	if (tmp % 2 == 1) cout << "IMPOSSIBLE" << endl;
	else cout << tmp / 2 << endl;
	return 0;
}