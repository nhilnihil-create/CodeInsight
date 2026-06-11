#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[52],b[52];
map<pair<ll,ll>,ll>c;
int main() {
	ll n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			ll nowx=a[i]-a[j];
			ll nowy=b[i]-b[j];
			pair<ll,ll> now=make_pair(nowx,nowy);
			c[now]++;
			ans=max(c[now],ans);
		}
	}
	cout << n-ans;
	// your code goes here
	return 0;
}