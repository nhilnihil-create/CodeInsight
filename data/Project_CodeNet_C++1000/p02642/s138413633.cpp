#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	vector<int> a((1e6+5),0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(a[v[i]]==0){
			for(ll j=v[i];j<a.size();j+=v[i])a[j]++;
		}
		else{
			a[v[i]]++;
		}
	}
	ll ans=0;
	for(int i=0;i<v.size();i++){
		if(a[v[i]]==1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
