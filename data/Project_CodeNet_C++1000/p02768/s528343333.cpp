#include <bits/stdc++.h>
#include <math.h>

using namespace std;

template<typename T>
long long modpow(const T n,const T p,const T mod);
template<typename T>
long long modinv(const T n,const T mod);
template<typename T>
bool chmax(T &a,const T &b);
template<typename T>
bool chmin(T &a,const T &b);

long long inf=1000000007;

int main(){
	long long n,a,b;
	cin>>n>>a>>b;
	long long ans=modpow((long long)2,n,inf)-1;
	
	long long ncr=1;
	
	for(long long i=n;i>n-a;i--){
	    ncr*=i;
	    ncr%=inf;
	}
	
	for(long long i=1;i<=a;i++){
	    ncr*=modinv(i,inf);
	    ncr%=inf;
	}
	
	ans-=ncr;
	if(ans<0) ans+=inf;
	ncr=1;
	
	for(long long i=n;i>n-b;i--){
	    ncr*=i;
	    ncr%=inf;
	}
	
	for(long long i=1;i<=b;i++){
	    ncr*=modinv(i,inf);
	    ncr%=inf;
	}
	
	ans-=ncr;
	if(ans<0) ans+=inf;
	
	cout<<max(ans,(long long)0)<<endl;
	
	return 0;
}

template<typename T>
long long modpow(const T n,const T p,const T mod){
	if(p==0) return 1;
	if(p%2==0){
		long long a=modpow(n,p/2,mod);
		return a*a%mod;
	}
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}

template<typename T>
long long modinv(const T n,const T mod){
	return modpow(n,mod-2,mod);
}

template<typename T>
bool chmax(T &a,const T &b){
	if(a<b){
		a=b;
		return 1;
	}
	return 0;
}

template<typename T>
bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return 1;
	}
	return 0;
}

