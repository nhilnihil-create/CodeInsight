#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
  
  ll n,k;cin>>n>>k;
  unordered_map<ll,ll> mp;
  
  for(ll i=0;i<k;i++){
  	ll d;cin>>d;
    for(ll j=0;j<d;j++){
    	ll x;cin>>x;
      	mp[x]=i;
    }
  }  
  
  cout<<n-mp.size()<<endl;
  
	return 0;	
}