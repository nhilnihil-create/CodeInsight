#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

int main() {
	ll l, r;
	cin >> l >> r;
	if (r - l + 1 >= 2019) {
		cout << 0 << endl;
		return 0;
	}
	ll R = r % 2019;
	ll L = l % 2019;
	if (R<L) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 2019;
	for (ll i = L; i <= R; i++) {
		for (ll j = i+1; j <= R; j++) {
			ll a = (i * j) % 2019;
			ans = min(ans, a);
		}
	}
	cout << ans << endl;
}
