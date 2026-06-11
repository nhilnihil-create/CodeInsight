#include "bits/stdc++.h" 
using namespace std; 
#define MAXN 1000001 
 
#define ll long long int

int main(){

	ll sum = 0;
	ll k;
	cin>>k;
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=k;j++){
			ll g = __gcd(i,j);
			for(ll l=1;l<=k;l++){
				sum+= __gcd(g,l);
			}
		}
	}
	cout<<sum;
	return 0; 
} 
