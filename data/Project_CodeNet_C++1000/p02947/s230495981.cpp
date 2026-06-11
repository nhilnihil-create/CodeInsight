#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mod 1e9+7
#define debug(x) cout<<x<<endl;
#define fi first
#define se second
int main(){
	ll n; cin>>n;
    string x;
	map<string,ll> m;
	while(n--) cin>>x,sort(x.begin(),x.end()),m[x]++;
	ll ans=0;
	for(auto it:m){
		ll p=it.second;
		ans+=(p*(p-1))/2;
	}
	cout<<ans;
}
