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
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	int ans = INF;
	for (int i = 1; i <= 100; i++) {
		int total = 0;
		for (int j = 0; j < n; j++) {
			total += (x[j] - i) * (x[j] - i);
		}
		ans = min(ans, total);
	}
	cout << ans << endl;
	return 0;
}