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
	int k;
	cin >> k;
	vector<ll> array;
	for (int i = 1; i <= 9; i++) array.push_back(i);
	while (1) {
		if (k <= array.size()) {
			cout << array[k - 1] << endl;
			return 0;
		}
		k -= array.size();
		vector<ll> old;
		swap(array, old);
		for (ll x : old) {
			if (x % 10 == 0) {
				array.push_back(10 * x);
				array.push_back(10 * x + 1);
			}
			else if (x % 10 == 9) {
				array.push_back(10 * x + 8);
				array.push_back(10 * x + 9);
			}
			else {
				array.push_back(10 * x + x % 10 - 1);
				array.push_back(10 * x + x % 10);
				array.push_back(10 * x + x % 10 + 1);
			}
		}
	}
	return 0;
}