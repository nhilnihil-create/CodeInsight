#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

#define DIV 1000000007
long long kaidan[10000000];

void kaical(long long n){
	kaidan[0] = 1;
	for(long long i = 1; i < n; i++){
		kaidan[i] = kaidan[i-1] * i;
		kaidan[i] %= DIV;
	}
}

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
	long long n_kai = kaidan[n];
	long long k_kai = kaidan[k];
	long long nmk_kai = kaidan[n-k];

	long long ans = n_kai * modpow(k_kai, DIV - 2);
	ans %= DIV;
	ans *= modpow(nmk_kai, DIV-2);
	ans %= DIV;
	return ans;
}

int main(){
	long long X, Y;
	cin >> X >> Y;
	if(X > Y) swap(X, Y);

	long long pat1 = Y - X;
	Y -= pat1*2;
	X -= pat1;
	if(X < 0) {
		cout << 0 << endl;
		return 0;
	}

	if(X % 3 != 0){
		cout << 0 << endl;
		return 0;
	}

	pat1 += X/3;
	long long pat2 = X/3;


	kaical(1000005);
	cout << combination(pat1+pat2, pat1) << endl;




}
