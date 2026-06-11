#include<bits/stdc++.h>
using namespace std;
map<long long,long long> m;
long long a[100005],ans=1,mod=998244353;
long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res%mod;
}
int main(){
	long long n,num=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) num++;
		m[a[i]]++;
	}
	if(a[1]!=0||num>1){
		cout<<0<<endl;
		return 0;
	}
	for(auto x:m){
		if(x.first==0) continue;
		ans=ans%mod*qpow(m[x.first-1],x.second)%mod;
	}
	cout<<ans%mod<<endl;
}