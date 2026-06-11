#include<bits/stdc++.h>
#define ll long long
#define mod (long long)(1e9+7)
#define endl "\n"
using namespace std;


void solve(){
	ll n,x,t;
	cin>>n>>x>>t;
	cout<<(n/x)*t+(n%x!=0?t:0)<<endl;
}


int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
