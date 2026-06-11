#include<iostream>
using namespace std;
const int mod=1e9+7;
long long qpow(long long x,long long p){
	long long ans=1;
	while(p){
		if(p&1)
			ans=(ans*x)%mod;
		x=(x*x)%mod;
		p>>=1;
	}
	return ans%mod;
}
int main(){
	long long n;
	cin>>n;
	if(n<2){
		cout<<"0\n";
		return 0;
	}
	long long ans=(((qpow(10,n)%mod-qpow(9,n)%mod+mod)%mod-qpow(9,n)%mod+mod)%mod+qpow(8,n)%mod)%mod;
	cout<<ans<<'\n';
}