#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << modpow(m, n, mod) << endl;
	return 0;
}
