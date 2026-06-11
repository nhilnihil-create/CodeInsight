#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,l,a[200],ans=0;
	cin>>n>>l;
	for(ll i=0;i<n;i++){
		a[i]=l+i+1-1;
	}
	for(ll i=0;i<n;i++){
		ans+=a[i];
	}
	ll ch=inf;
	ll ans2=0;
	for(ll i=0;i<n;i++){
		ll now=ans-a[i];
		if(abs(now-ans)<ch){
			ch=abs(now-ans);
			ans2=now;
		}
	}
	cout <<ans2;
	// your code goes here
	return 0;
}