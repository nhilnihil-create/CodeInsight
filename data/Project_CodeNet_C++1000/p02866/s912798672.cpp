#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
long long INF = (1LL<<62);

const LL C = 998244353;

LL powmod(LL base, LL k, LL mod){
	if(k == 0){ return 1; }
	if(k == 1){ return (base % mod); }

	LL q = k / 2;
	LL r = k % 2;
	LL u = powmod((base*base)%mod, q, mod);
	LL v = powmod(base, r, mod);
	return ( (u * v ) % mod );
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> D;
	for(int i=0; i<N; i++){
		LL d; cin >> d;
		D.push_back(d);
	}
	if(D[0] != 0){
		printf("0\n");
		return 0;
	}
	sort(D.begin(), D.end());
	LL maxd = D[D.size()-1];
	if(D[1] == 0 || maxd > N-1){
		printf("0\n");
		return 0;
	}
	
	vector<LL> V(maxd + 1, 0);
	for(int i=0; i<N; i++){
		V[D[i]]++;
	}
	LL ans = 1;
	for(int d=1; d<=maxd; d++){
		if(V[d] == 0){
			printf("0\n");
			return 0;
		}
		ans *= powmod(V[d-1], V[d], C);
		ans %= C;
	}
	ans %= C;
	printf("%lld\n", ans);
	return 0;
}