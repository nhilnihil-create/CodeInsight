#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ch[200010];
	for(ll i=0;i<k;i++){
		cin>>ch[i];
	}
	ll ans=n-ch[k-1]+ch[0];
	for(ll i=1;i<k;i++){
		ll now=ch[i]-ch[i-1];
		ans=max(now,ans);
	}
	cout <<n-ans;
	return 0;
}