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

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> num(n + 2);
	num[n + 1] = 1;
	for (int i = n; i > 0; i--) {
		num[i] = num[i + 1] - n + (ll)i * 2;
	}
	ll ans = 0;
	for (int i = k; i < n + 2; i++) {
		ans += num[i] % mod;
	}
	ans = (ans + mod) % mod;
	cout << ans << endl;
	return 0;
}