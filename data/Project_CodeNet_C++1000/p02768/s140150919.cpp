#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007 

long long n, a, b;

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= DIV;
		}
		ori *= ori;
		ori %= DIV;
		po >>= 1;
	}
	return res;
}

//nCk
long long combination(long long n, long long k){
	if(n == 0 && k == 0)return 1;
	if(n < k || n < 0)return 0;

	long long ue = 1;
	long long shita = 1;

	for(long long i = 0; i < k; i++) {
		ue *= (n - i);
		ue %= DIV;
	}

	for(long long i = 1; i <= k; i++) {
		shita *= modpow(i, DIV - 2);
		shita %= DIV;
	}
	return (ue * shita)%DIV;
}


int main(){
	cin >> n >> a >> b;

	long long ans = modpow(2, n);

	ans -= combination(n, a);
	ans -= combination(n, b);
	ans--;
	ans += DIV * 10L;
	ans %= DIV;
	cout << ans << endl;

}