#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll h, ans = 0;
	cin >> h;
	ll i = 1;
	while (h >= 1) {
		ans += i;
		h /= 2;
		i *= 2;
	}
	cout << ans << endl;
	return 0;
}
