#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
	ll n; cin>>n;
	ll x[n]={};
	rep(i,n) cin>>x[i];
	ll ans=(1<<30),k=0;
	for(int p=0; p<=101; p++){
		ll k=0;
		for(int i=0; i<n; i++){
			k+=(x[i]-p)*(x[i]-p);
		}
		ans=min(k,ans);
	}
	cout<<ans<<endl;
}
		
	