#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 10000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>ch;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ch.push_back(now);
	}
	sort(ch.begin(),ch.end());
	ll ans=0;
	for(ll i=n-1;i>=2;i--){
		for(ll j=i-1;j>=1;j--){
			ll las=ch[i]-ch[j]+1;
			auto itr=lower_bound(ch.begin(),ch.end(),las);
			ll ban=itr-ch.begin();
			ans+=max(ll(0),j-ban);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}