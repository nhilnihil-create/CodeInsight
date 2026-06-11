#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gya(ll n,ll p,ll m){
	ll b=1;
	while(p>0){
		if(p%2)b=(b*n)%m;
		n=(n*n)%m;
		p/=2;
	}
	return b;
}
int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll mod=1e9+7;
	ll numa=1,numb=1,na=1,nb=1;
	for(int i=1;i<=a;i++){
		numa*=i;
		numa%=mod;
		na*=n-i+1;
		na%=mod;
	}
	for(int i=1;i<=b;i++){
		numb*=i;
		numb%=mod;
		nb*=n-i+1;
		nb%=mod;
	}
	numa=gya(numa,mod-2,mod);
	numb=gya(numb,mod-2,mod);
	na*=numa;
	na%=mod;
	nb*=numb;
	nb%=mod;
	ll ans=gya(2,n,mod);
	ans+=mod-1;
	ans%=mod;
	ans+=2*mod-na-nb;
	ans%=mod;
	cout<<ans;
	return 0;
}
