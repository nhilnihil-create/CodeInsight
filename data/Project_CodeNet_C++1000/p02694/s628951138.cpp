#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll x, n = 100, ans = 0;
	cin >> x;
	while (n < x) {
		n += n / 100;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
