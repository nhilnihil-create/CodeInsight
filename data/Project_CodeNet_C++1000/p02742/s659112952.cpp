#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(0);
	ll h, w;
	cin >> h >> w;
	if (h == 1 || w == 1) cout << "1" << "\n";
	else {
		ll ans = h * w;
		if (ans % 2 == 0) cout << ans / 2 << "\n";
		else cout << ans / 2 + 1 << "\n";
	}
	return 0;
}
