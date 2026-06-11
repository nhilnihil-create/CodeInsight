#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,m;
	cin>>n>>m;
	multiset<ll,greater<ll>> a;
	ll ans=0;
	for(ll i=0; i<n; i++){
		ll b=0;
		cin>>b;
		a.insert(b);
		ans+=b;
	}
	
	for(ll i=0; i<m; i++){
		ll k=0;
		for(ll j:a){//aの一番大きい数
			k=j;
			if(k>0){
				break;
			}
		}
		ans-=k-(k/2);
		a.insert(k/2);
		a.erase(a.find(k));
	}
	
	cout<<ans<<endl;
}
	
	