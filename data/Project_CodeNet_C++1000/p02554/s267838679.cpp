#include"bits/stdc++.h"
//#include"atcoder.h"
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const ll inf = ll(1e18) + 1;
const ll mod = pow(10,9)+7;

ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % mod;
	}
	return res;
}

int main() {
	ll n;
	cin >> n;

	ll result = powmod(10,n);
	result -= powmod(9,n);
	result -= powmod(9, n);
	result += powmod(8, n);

	result %= mod;
	result = (result + mod) % mod;

	cout << result << endl;

	return 0;
}
