#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	ll t=0;
for(ll i=0;i<n;i++){
	cin>>a[i];
	if(a[i]>=k){
		t++;
	}
}

cout<<t;
	
	return 0;
}