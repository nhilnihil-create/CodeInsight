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
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i < n + 1; i++) {
		if (i % 3 != 0 && i % 5 != 0) {
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}