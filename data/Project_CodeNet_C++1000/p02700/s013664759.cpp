#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (a > 0 && c > 0) {
		c -= b;
		if (c <= 0) break;
		a -= d;
		if (a <= 0) break;
	}
	if (a > 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}