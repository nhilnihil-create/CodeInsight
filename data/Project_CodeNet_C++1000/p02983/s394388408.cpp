#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62

int main() {
	ll l,r;
	cin>>l>>r;
	ll ans=INF;
	for(ll i=l;i<=min(l+3000,r);i++){
		for(ll j=i+1;j<=min(i+1+3000,r);j++){
			ll now=i*j;
			now%=2019;
			ans=min(ans,now);
		}
	}
	cout <<ans;
	return 0;
}