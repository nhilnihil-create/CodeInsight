#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	ll a[22],b[22],c[22];
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];a[i]--;
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	for(ll i=0;i<n;i++){
		cin>>c[i];
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now=a[i];
		ans+=b[now];
	}
	for(ll i=0;i<n;i++){
		if(i==n-1){
			continue;
		}
		ll now=a[i];
		if(now==n){
			continue;
		}
		ll nex=a[i+1];
		if(now+1==nex){
			ans+=c[now];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}