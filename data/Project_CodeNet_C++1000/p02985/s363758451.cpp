#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100005],mod=1e9+7;
int main(){
	ll n,k,ans=1,num=2;
	cin>>n>>k;
	for(ll i=1;i<n;i++){
		ll u,v;cin>>u>>v;
		d[u]++;d[v]++;
	}
	if(n<=3){
		for(ll i=0;i<n;i++){
			ans=(ans%mod*(k-i)%mod)%mod;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(d[i]>=3){
			for(ll j=3;j<=d[i];j++){
				ans=(ans%mod*(k-j)%mod)%mod;num++;
			}
		}
	}
	ans=(ans%mod*k%mod*(k-(ll)1)%mod)%mod;
	//cout<<ans<<" "<<num<<endl;
	for(int i=num+1;i<=n;i++){
		ans=(ans%mod*(k-2)%mod)%mod;
	}
	cout<<ans%mod<<endl;
}