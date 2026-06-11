#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const ll inf = ll(1e18) + 1;
const ll mod = pow(10,9)+7;

ll powMod(ll a, ll n, ll mod) {//aのn乗を計算します。
	ll x = 1;
	while (n > 0) {//全てのbitが捨てられるまで。
		if (n & 1) {//1番右のbitが1のとき。
			x = x * a % mod;
		}
		a = a * a % mod;
		n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
	}
	return x;
}

int main() {
	ll n;
	cin >> n;

	ll result = powMod(10,n,mod);
	result -= powMod(9,n,mod);
	result -= powMod(9, n, mod);
	result += powMod(8, n, mod);

	result %= mod;
	result = (result + mod) % mod;

	cout << result << endl;

	return 0;
}
