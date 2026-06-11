#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

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
	ll N, K;
	cin >> N >> K;

	kaical(N + 5);


	for(ll i = 1; i <= K; i++) {
			cout << (combination(N-K+1, i) * combination(K-1, i -1)) %DIV << endl;
	}
}