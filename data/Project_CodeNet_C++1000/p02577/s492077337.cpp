#include<bits/stdc++.h>
#define ll long long
#define mod (long long)(1e9+7)
#define endl "\n"
using namespace std;


void solve(){
	string s;
	cin>>s;
	ll n=s.length();
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans=(ans+(s[i]-'0'))%9;
	}
	if(ans==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}


int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
