#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll a[50],b[50];
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	ll ans=0;
	map<pair<ll,ll>,ll>c;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i==j){
				continue;
			}
			ll dx=a[i]-a[j];
			ll dy=b[i]-b[j];
			c[make_pair(dx,dy)]++;
			ans=max(ans,c[make_pair(dx,dy)]);
		}
	}
	cout << n-ans;
	// your code goes here
	return 0;
}