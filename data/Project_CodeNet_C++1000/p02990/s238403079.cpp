#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll fact[100001];

ll modpow(ll a, ll n){
	ll res = 1;
	while (n > 0){
		if (n & 1) res = res * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return res;
}

ll modinv(ll a){
	return modpow(a, MOD-2);
}

ll nCr(ll n , ll r){
	return ((fact[n]*modinv(fact[n-r]))%MOD*modinv(fact[r]))%MOD;
}

int main(){
	ll n, k;
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++){
		fact[i] = fact[i-1]*i%MOD;
	}
	for (int i = 1; i <= k; i++){
		if (n - k < i - 1){
			cout << 0 << endl;
		}else{
			ll hoge = nCr(k-1, i-1);
			hoge *= (fact[n-k-(i-1)+i]*modinv(fact[n-k-(i-1)])%MOD)*modinv(fact[i])%MOD;
			hoge %= MOD;
			cout << hoge << endl;
		}
	}
	return  0;
}