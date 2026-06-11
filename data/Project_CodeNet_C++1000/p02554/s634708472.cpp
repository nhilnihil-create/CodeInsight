#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;
ll powermod(ll n, ll x){
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
	ll N;
	cin >> N;
	ll a = powermod(10, N);
	ll b = (2 * powermod(9, N))%MOD;
	ll c = ((a-b)%MOD+MOD)%MOD;
	ll d = c + powermod(8, N);
	ll e = d % MOD;
	cout << e;
}
