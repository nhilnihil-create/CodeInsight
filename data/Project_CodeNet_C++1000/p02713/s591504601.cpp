#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int k;
	cin >> k;
	ll ans = 0;
	for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) for (int m = 1; m <= k; m++) {
		ans += gcd(gcd(i, j), m);
	}
	cout << ans << endl;
	return 0;
}