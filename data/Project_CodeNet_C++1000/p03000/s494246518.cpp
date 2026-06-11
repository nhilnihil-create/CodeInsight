#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,x;
	cin>>n>>x;
	ll ans=1;
	ll now=0;
	for(ll i=0;i<n;i++){
		ll z;
		cin>>z;
		now+=z;
		if(now<=x){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}