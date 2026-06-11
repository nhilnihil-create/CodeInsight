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
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	int max_len = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			max_len = max(max_len, a[i] - a[i - 1]);
		}
	}
	max_len = max(max_len, a[0] + k - a[n - 1]);
	int ans = k - max_len;
	cout << ans << endl;
	return 0;
}