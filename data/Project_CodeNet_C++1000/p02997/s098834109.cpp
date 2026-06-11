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
	ll n,k;
	cin>>n>>k;
	ll cnt=(n-1)*(n-2)/2;
	if(cnt<k){
		cout << -1;
		return 0;
	}
	cout << n-1+cnt-k<<endl;
	for(ll i=0;i<n-1;i++){
		cout << 1<<" "<<i+2<<endl;
	}
	ll now=cnt-k;
	if(now==0){
		return 0;
	}
	for(ll i=2;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			now--;
			cout << i<<" "<<j<<endl;
			if(now==0){
				return 0;
			}
		}
	}
	// your code goes here
	return 0;
}