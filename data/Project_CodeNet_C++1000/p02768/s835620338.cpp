#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
const LL mod=1e9+7;
const int Max_Num=2e5+10;

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

int main(){
	LL n, a, b;
	cin >> n >> a >> b;
	vector<LL> comb;
	comb.emplace_back(1LL);
	rep(i,Max_Num){
		LL c=comb[i]*(n-i)%mod*modinv(i+1);
		c%=mod;
		comb.emplace_back(c);
	}
	LL ans=modpow(2,n)-1;
	ans-=comb[a]+comb[b];
	while(ans<0) ans+=mod;
	cout << ans << endl;

	return 0;
}