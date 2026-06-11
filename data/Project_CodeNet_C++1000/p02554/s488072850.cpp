#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll quick(ll a,ll b){
	ll res =1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	ll n;
	cin>>n;
	ll ans=((quick(10,n)-2*quick(9,n)+quick(8,n))%mod+mod)%mod;
	cout<<ans<<"\n";
	return 0;
}