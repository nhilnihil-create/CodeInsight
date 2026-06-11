#include <bits/stdc++.h>
int read(){
	int x=0,f=1;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x*f;
}
using Int = signed long long int;
const int N=100000+10;
const Int mod=Int(1e9)+7LL;

int vis[N],phi[N],prime[N],pcnt;
Int qpow(Int a,Int p){
	Int r=1; while(p){
		if(p&1) r=r*a%mod;
		a=a*a%mod; p>>=1;
	} return r;
}

void sieve(){
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			prime[pcnt++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<pcnt&&1LL*i*prime[j]<N;j++){
			int t=i*prime[j]; vis[t]=1;
			if(i%prime[j]==0){ phi[t]=phi[i]*prime[j]%mod; break; }
			phi[t]=phi[i]*(prime[j]-1)%mod;
		}
	}
}

int main(){
	int n=read(),k=read();
	sieve();


	Int ans=0;
	for(int i=1;i<=k;i++) ans=(ans+qpow(k/i,n)*phi[i]%mod)%mod;
	std::cout<<ans<<std::endl;
	return 0;
}