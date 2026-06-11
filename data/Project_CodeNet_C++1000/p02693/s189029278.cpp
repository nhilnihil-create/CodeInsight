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
	int k, a, b;
	cin >> k >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}
	cout << "NG" << endl;
	return 0;
}