#include <bits/stdc++.h>
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
int main(){
	int k;
	cin >> k;
	if(k%7==0){
		for(int i = 1; i <= k; ++i){
			if(__gcd(10, 9*(k/7)) != 1){
				cout << -1;
				return 0;
			}
			if(modpow(10, i, 9*(k/7)) == 1){
				cout << i;
				return 0;
			}
		}
	}
	else{
		for(int i = 1; i <= k; ++i){
			if(__gcd(10, 9*k) != 1){
				cout << -1;
				return 0;
			}
			if(modpow(10, i, 9*k) == 1){
				cout << i;
				return 0;
			}
		}

	}
	if(k == 1){
		cout << 1;
	}
	else{
		cout << -1;
	}
}
