#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	ll a[20],b[20],c[20];
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x--;
		a[i]=x;
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	for(ll i=0;i<n-1;i++){
		cin>>c[i];
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now=a[i];
		ans+=b[now];
		if(i!=n-1){
			ll next=a[i+1];
			if(next==now+1){
				ans+=c[now];
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}