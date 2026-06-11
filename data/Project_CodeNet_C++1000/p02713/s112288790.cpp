#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dep(ll a,ll b){
	if(b==0){
		return a;
	}
	return dep(b,a%b);
}
int main() {
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				ll now=dep(max(i,j),min(j,i));
				now=dep(max(now,k),min(k,now));
				ans+=now;
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}