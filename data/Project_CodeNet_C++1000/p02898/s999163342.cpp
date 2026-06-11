#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		if(now>=k){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}