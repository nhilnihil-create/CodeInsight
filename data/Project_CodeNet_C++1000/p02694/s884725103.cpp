#include<iostream>
#include<string>
#include<vector>
#include<cmath>
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
	ll x;
	cin >> x;
	ll ans = 0;
	ll money = 100;
	while (money < x) {
		ans++;
		money = money + money / 100;
	}
	cout << ans << endl;
	return 0;
}