#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main(){
	ll n; cin>>n;
	ll ans=n-1;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			int a=i;
			int b=n/i;
			ans=min(ans,i+n/i-2);
		}
	}
	cout<<ans;
}
