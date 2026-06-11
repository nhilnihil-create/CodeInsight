#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n;
	cin>>n;
	ll ch[102];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=INF;
	for(ll i=0;i<=100;i++){
		ll cnt=0;
		for(ll j=0;j<n;j++){
			cnt+=(i-ch[j])*(i-ch[j]);
		}
		ans=min(ans,cnt);
	}
	cout <<ans;
	// your code goes here
	return 0;
}