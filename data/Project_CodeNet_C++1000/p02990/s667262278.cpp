#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

struct Combination {
	vector<long long> inv,finv,fac;
	Combination(int n, int kmax) : inv(kmax+1),finv(kmax+1),fac(kmax){
		if(kmax>=1){
			inv.at(1)=1;
			finv.at(1)=1;
			fac.at(0) = n;
		}
	for(int i=2; i<=kmax; i++) inv.at(i) = MOD - inv.at(MOD%i) * (MOD/i) %MOD;
	for(int i=2; i<=kmax; i++) finv.at(i) = finv.at(i-1) * inv.at(i) % MOD;
	for(int i=1; i<kmax; i++) fac.at(i) = fac.at(i-1) * (n-i) % MOD;
	}
	ll comb(int k) {return (k ? fac.at(k-1) * finv.at(k) % MOD : 1 );}
};

int main(){
	
	int n,k; cin>>n>>k;
	Combination c(k-1,k-1),d(n-k+1,k);
	for(int i=k-1; i>=0; i--){
		cout << (c.comb(i) * d.comb(k-i))%MOD << endl;
	}
	
}