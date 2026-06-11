#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll x,n;
	cin>>x>>n;
	ll arr[n];
	for(ll i=0;i<=n-1;i++){
		cin>>arr[i];
	}

	unordered_set<ll> us1;

	for(ll i=0;i<=n-1;i++){
		us1.insert(arr[i]);
	}

	ll ans = x;
	ll dif = INT_MAX;
	for(ll i = x;i>=x-1-n;i--){
		if(us1.find(i)==us1.end()){
			dif = abs(i-x);
			ans  = i;
			break;
		}
	}

	for(ll i = x;i<=x+1+n;i++){
		if(us1.find(i)==us1.end()){
			if(abs(i-x) < dif){
				ans = i;
				break;
			}
			break;
		}
	}
	cout<<ans;

}