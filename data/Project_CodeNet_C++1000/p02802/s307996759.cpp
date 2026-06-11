#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	bool ac[100010]={false};
	ll wa[100010]={};
	ll ans=0;
	for(ll i=0;i<k;i++){
		ll x;string s;
		cin>>x>>s;
		x--;
		if(ac[x]){
			continue;
		}
		if(s=="AC"){
			ac[x]=true;
			ans++;
		}
		else{
			wa[x]++;
		}
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		if(ac[i]){
			cnt+=wa[i];
		}
	}
	cout << ans<<" "<<cnt;
	// your code goes here
	return 0;
}