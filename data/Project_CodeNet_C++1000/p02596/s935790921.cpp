#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll modpow(ll n, ll x, ll MOD){
	ll ret = 1;
	while(x){
		if(x&1){
			(ret*=n)%=MOD;
		}
		x >>= 1;
		(n*=n)%=MOD;
	}
	return ret;
}
int solve(int k, int MOD){
	if(__gcd(10, MOD) != 1){
		return -1;
	}
	for(int i = 1; i < MOD; ++i){
		if(modpow(10, i, MOD) == 1){
			return i;
		}
	}
}
int main(){
	int k;
	cin >> k;
	if(k%7 == 0){
		cout << solve(k, 9*(k/7));
	}
	else{
		cout << solve(k, 9*k);
	}
}
