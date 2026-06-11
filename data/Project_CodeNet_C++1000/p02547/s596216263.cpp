#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


void solve(){
	
	ll n; cin>>n;
	
	ll a[n],b[n];
	
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	
	ll ans=0,curr=0;
	
	for(int i=0; i<n; i++){
		if(a[i]==b[i]){
			curr++;
		}
		else{
			ans=max(ans,curr);
			curr=0;
		}
	}
	
	ans=max(ans,curr);
	
	if(ans>=3){
		cout<<"Yes"<<"\n";
	}
	else{
		cout<<"No"<<"\n";
	}
	
	return;
}




int main() {
	
	
	

   int t=1; //cin>>t;
   
   while(t--){
   	solve();
   }
    
    
    return 0;
}