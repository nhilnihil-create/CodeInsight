#include <bits/stdc++.h>
using namespace std;

const long mod = 1e9+7;

long modpow(long a, long b){
	long res = 1;
	while (b > 0){
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

long comb(long a,long b){
	if(a<=0 || b<=0)return 1;
	long x = 1, y = 1;
	for (int i = 1; i <= b; i++){
		x = x * (a - i + 1) % mod;
		y = y * i % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main(){
	long N, A, B;
	cin >> N >> A >> B;
	long ans = modpow(2, N);
	ans--;
	ans += mod - comb(N, A);
	ans %=mod;
	ans += mod - comb(N, B);
	ans %= mod;
	cout << ans << endl;
}