#include<iostream>
// #include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<deque>


#define REP(i,a,b) for(int i = (a); i < b; ++i)
#define inf 1e9+10
#define MOD 1000000007

using ll = long long;
using ull = unsigned long long;
using namespace std;

inline ll modpow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

inline ll mod(ll val, ll m) {
	ll res = val % m;
	if (res < 0) res += m;
	return res;
}


int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2;
	}
	else {
		cout << n / 2 + 1;
	}

	return 0;
}