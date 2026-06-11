#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = max(max((ll)a * c, (ll)a * d), max((ll)b * c, (ll)b * d));
	cout << ans << '\n';
	return 0;
}
