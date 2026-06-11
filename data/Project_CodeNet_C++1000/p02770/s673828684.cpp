#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int k,q;
ll d[5005];
ll times[5005];
int main(){
	cin>>k>>q;
	
	for (int x=0;x<k;x++) cin>>d[x];
	
	
	int len,seed,mod;
	while (q--){
		cin>>len>>seed>>mod;
		
		len--;
		for (int x=0;x<k;x++) times[x]=len/k+(len%k>x);
		
		ll total=seed%mod;
		ll ans=0;
		
		for (int x=0;x<k;x++){
			total+=times[x]*(d[x]%mod);
			if (d[x]%mod) ans+=times[x];
		}
		
		ans-=total/mod;
		cout<<ans<<endl;
	}
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int k,q;
ll d[5005];
ll times[5005];
int main(){
	cin>>k>>q;
	
	for (int x=0;x<k;x++) cin>>d[x];
	
	
	int len,seed,mod;
	while (q--){
		cin>>len>>seed>>mod;
		
		len--;
		for (int x=0;x<k;x++) times[x]=len/k+(len%k>x);
		
		ll total=seed%mod;
		ll ans=0;
		
		for (int x=0;x<k;x++){
			total+=times[x]*(d[x]%mod);
			if (d[x]%mod) ans+=times[x];
		}
		
		ans-=total/mod;
		cout<<ans<<endl;
	}
}
*/