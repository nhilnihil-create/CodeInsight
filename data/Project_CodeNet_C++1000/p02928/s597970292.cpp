#include<bits/stdc++.h>
using namespace std;
int a[2005],n,k;
const int mod=1e9+7;
int calc(int K){
	return (1ll*K*(K+1)/2)%mod;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j)
			if(a[j]>a[i]) ans=(ans+calc(k))%mod;
			else if(a[j]<a[i]) ans=(ans+calc(k-1))%mod;
	}
	cout<<ans;
	return 0;
}