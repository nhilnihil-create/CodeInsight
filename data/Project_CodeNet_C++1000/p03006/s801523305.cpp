#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll a[52],b[52];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		a[i]=x;b[i]=y;
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ll sum=0;
			if(i==j){
				continue;
			}
			ll nox=a[j]-a[i];
			ll noy=b[j]-b[i];
			for(ll k=0;k<n;k++){
				for(ll l=0;l<n;l++){
					ll nex=a[l]-a[k];
					ll ney=b[l]-b[k];
					if(nex==nox&&noy==ney){
						sum++;
					}
				}
			}
			ans=max(ans,sum);
		}
	}
	cout << n-ans;
	// your code goes here
	return 0;
}