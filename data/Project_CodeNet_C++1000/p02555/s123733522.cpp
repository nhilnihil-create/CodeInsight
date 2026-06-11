#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = (ll)1e9 + 7;
const int MAX = 2020;
vector<int> fact,invf;

ll pwr(ll a, ll n){
	if(n==0) return 1;
	ll q = pwr(a,n/2);
	q = q * q % MOD;
	if(n&1) q = q * a % MOD;
	return q; 
}
ll inv(ll a){
	return pwr(a,MOD-2);
}

ll add(ll a, ll b){
	a += b;
	if(a >= MOD)
		a -= MOD;
	return a;	
}

ll mul(ll a, ll b){
	return a * b % MOD;
}

void init(){
	fact.resize(MAX);
	invf.resize(MAX);
	fact[0] = 1;
	for(int i = 1; i < MAX; i++){
		fact[i] = mul(fact[i-1],i); 
	}
	invf[MAX-1] = inv(fact[MAX-1]);
	for(int i = MAX-2; i >= 0; i--){
		invf[i] = mul(invf[i+1],i+1);
	}
}
ll C(int n, int k){
	if(k > n || n < 0 || k < 0) return 0;
	return mul(fact[n], mul(invf[n-k],invf[k]));
}


int main(){
	init();
	ll res = 0;
	ll S; cin >> S;
	for(int i = 1; i <= S; i++){
		ll take = 3 * i;
		ll remS = S - take;
		ll tmp = C(remS+i-1,i-1);
		//cout << tmp << "\n";
		res = add(res,tmp);
	}
	cout << res << "\n";
	return 0;
}
