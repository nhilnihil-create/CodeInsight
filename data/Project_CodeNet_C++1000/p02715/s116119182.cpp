#include<iostream>
#include<algorithm>
#include <string>
#include <cstring>
#include<climits>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
ll d[100001];
ll mod = 1e9 + 7;
ll go(ll x, ll y) {
	if (y == 0)return 1;
	else if (y == 1)return x;
	else if (y & 1) {
		return x * go(x, y - 1) % mod;
	}
	else {
		ll tmp = go(x, y / 2) % mod;
		return tmp * tmp%mod;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(NULL);

	ll n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		d[i] = go(k / i, n);
	}

	for (int i = k; i >= 1; i--) {
		for (int j = 2; j * i <= k; j++) {
			d[i] -= d[j  * i];
			while (d[i] < 0)d[i] += mod;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += d[i] * (ll)i;
		ans %= mod;
	}
	cout << ans << '\n';






}