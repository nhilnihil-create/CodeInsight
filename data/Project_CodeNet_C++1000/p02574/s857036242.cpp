#include<bits/stdc++.h>
#define ll long long
#define mod (long long)(1e9+7)
#define endl "\n"
using namespace std;


void solve(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll mark=1;
	set<ll> mp;
	for(ll i=0;i<n;i++){
		ll x=a[i];
		if(x%2==0&&mp.find(2)!=mp.end()){
			mark=0;
			break;
		}
		while(a[i]%2==0){
			a[i]=a[i]/2;
			mp.insert(2);
		}
		for(ll j=3;j*j<=a[i];j+=2){
			if(a[i]%j==0){
				if(mp.find(j)!=mp.end()){
					mark=0;
					break;
				}
				else{
					mp.insert(j);
					while(a[i]%j==0)
						a[i]=a[i]/j;
				}
			}
		}
		if(a[i]>1){
			if(mp.find(a[i])!=mp.end()){
				a[i]=x;
				mark=0;
				break;
			}
			mp.insert(a[i]);
		}
		a[i]=x;
		if(!mark){
			break;
		}
	}
	if(mark){
		cout<<"pairwise coprime"<<endl;
	}
	else{
		ll ans=a[0];
		for(ll i=1;i<n;i++){
			ans=__gcd(ans,a[i]);
		}
		if(ans==1){
			cout<<"setwise coprime"<<endl;
		}
		else{
			cout<<"not coprime"<<endl;
		}
	}
}


int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
