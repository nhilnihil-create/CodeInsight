#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const ll mod=1e9+7;
ll fpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		b/=2;a=(a*a)%mod; 
	}
	return ans%mod;
}

int main()
{
	ll n;cin>>n;
	cout<<(fpow(10,n)+mod-(2*fpow(9,n))%mod+fpow(8,n))%mod;
	return 0;	
} 