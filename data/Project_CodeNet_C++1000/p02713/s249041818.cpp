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

int gcd(int a, int b, int c) {
	int res;
	int x = min({ a,b,c });
	bool flag = 1;
	while (flag) {
		if (a % x == 0 && b % x == 0 && c % x == 0) {
			flag = 0;
			res = x;
		}
		else {
			x--;
		}
	}
	return res;
}

int main() {
	int k;
	cin >> k;
	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int m = 1; m <= k; m++) {
				ans += gcd(i, j, m);
			}
		}
	}
	cout << ans << endl;
	return 0;
}