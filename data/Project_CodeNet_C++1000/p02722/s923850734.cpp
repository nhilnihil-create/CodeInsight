#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define all(v) (v.begin(),v.end())
#define ff first
#define ss second


int main(){
	fast;
	ll n,i,j,k;
	cin>>n;
	set<ll> d1,a;
	for(i=1;i*i<=(n-1);++i){
		if((n-1)%i==0){
			d1.insert(i);
			d1.insert((n-1)/i);
		}
		
	}
	for(ll x : d1){
		if(n%x==1)
			a.insert(x);
	}
	set<ll> d2;
	for(i=1;i*i<=n;++i){
		if(n%i==0){
			d2.insert(i);
			d2.insert(n/i);
		}
			
	}
	for(ll x : d2){
		ll t=n;
		//cout<<x<<" ";
		while(true){
			if(t%x!=0 || x==1)
				break;
			t/=x;
		}
		if(t%x==1)
			a.insert(x);
	}
	cout<<a.size();
	
}