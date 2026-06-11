#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll x = n / i;
		ans += i * x * (x + 1) /2;
	}
	cout << ans << endl;
	return 0;
}
