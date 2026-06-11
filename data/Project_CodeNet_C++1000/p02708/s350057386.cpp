#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	ll n, k;

	cin >> n >> k;

	ll c = 1;

	int ma = 0;
	int modi = 1e9 + 7;

	for (ll i = 0; i <= n ; i++) {
		ma += i;
	}

	ll min = ma, max = ma;

	for (ll i = n; i >= k;i--) {
		min -= i ;
		max -= (n-i);
		
		c += (max - min + 1);
		c %= modi;
	}

	c %= modi;

	cout << c << endl;

	return 0;
}