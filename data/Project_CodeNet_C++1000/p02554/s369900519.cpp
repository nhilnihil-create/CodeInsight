#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long
const ll mod=1e9+7;

ll bigMod(ll n,ll p){
	if(p==1) return n;

	if(p%2==0){
		ll ret=bigMod(n,p/2);
		return ((ret%mod)*(ret%mod))%mod;
	}
	else return n*bigMod(n,p-1)%mod; 
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	ll T,i,j;
	ll n;
	cin>>n;
	if(n<2) printf("0\n");
	else if(n==2) printf("2\n");
	else{
		ll res=(bigMod(10,n)-2*bigMod(9,n)+bigMod(8,n)+mod+mod)%mod;
		printf("%lld\n",res);
	}
		
		
	return 0;
}