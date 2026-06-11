#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[200010],b[200010];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	priority_queue<pair<ll,ll>>ch;
	for(ll i=0;i<n;i++){
		cin>>b[i];
		ch.push(make_pair(b[i],i));
	}
	ll ans=0;
	while(!ch.empty()){
		ll val=ch.top().first;
		ll i=ch.top().second;
		ch.pop();
		ll l=i-1;
		if(l<0){
			l=n-1;
		}
		ll r=i+1;
		if(r==n){
			r=0;
		}
		if(val<a[i]){
			cout << -1;
			return 0;
		}
		if(val==a[i]){
			continue;
		}
		ll m=((val)-a[i])/(b[l]+b[r]);
		if(m==0){
			cout << -1;
			return 0;
		}
		ans+=m;
		val=val-m*(b[l]+b[r]);
		ch.push(make_pair(val,i));
		b[i]=val;
	}
	cout <<ans;
	// your code goes here
	return 0;
}