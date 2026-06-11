#include<iostream>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll mi(ll a,ll b){
	ll x=1;
	while(b){
		if(b&1) x=x*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return x;
}
int main(){
	int n;
	cin>>n;
	ll ans=(mi(10,n)-mi(9,n)-mi(9,n)+mi(8,n))%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}