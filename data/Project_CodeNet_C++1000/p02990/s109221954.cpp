#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL mod =1e9+7;
const int Max_Num=2010;

LL F[Max_Num], Finv[Max_Num];

LL modpow(LL x, LL n){
	LL r=1;
	while(n){
		if(n&1) r=r*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return r;
}

LL modinv(LL x){
	LL m=mod, u=1, v=0;
	while(m){
		LL t=x/m;
		x-=t*m; swap(x,m);
		u-=t*v; swap(u,v);
	}
	u%=mod;
	if(u<0) u+=mod;
	return u;
}

LL comb(LL n, LL k){
	LL res=F[n];
	res*=Finv[k]*Finv[n-k]%mod;
	return res%mod;
}

void fact(){
	F[0]=1;
	rep(i,Max_Num-1){
		F[i+1]=F[i]*(i+1);
		F[i+1]%=mod;
	}
	rep(i,Max_Num) Finv[i]=modinv(F[i]);
}

int main(){
	fact();
	LL N, K;
	cin >> N >> K;
	for(LL i=0; i<K; i++){
		if(N-K-i<0){
			cout << 0 << endl;
			continue;
		}
		LL ans=1;
		ans*=comb(K-1,i);
		ans*=F[N-K+1]*Finv[N-K-i]%mod*Finv[i+1]%mod;
		ans%=mod;
		cout << ans << endl;
	}

	return 0;
}