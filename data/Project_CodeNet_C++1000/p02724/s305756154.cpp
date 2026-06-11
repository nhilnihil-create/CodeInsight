#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
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
	int x;
	cin >> x;
	int cnt_500 = x / 500;
	x -= 500 * cnt_500;
	int cnt_5 = x / 5;
	ll ans = (ll)1000 * cnt_500 + (ll)5 * cnt_5;
	cout << ans << endl;
	return 0;
}