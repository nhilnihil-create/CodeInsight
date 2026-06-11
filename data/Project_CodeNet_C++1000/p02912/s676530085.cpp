#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll cnt[100010];
int main() {
	ll n,k;
	cin>>n>>k;
	priority_queue<ll>q;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		q.push(now);
	}
	while(k!=0){
		k--;
		ll now=q.top();
		q.pop();
		now/=2;
		q.push(now);
	}
	ll ans=0;
	while(q.size()!=0){
		ll now=q.top();
		ans+=now;
		q.pop();
	}
	cout <<ans;
	// your code goes here
	return 0;
}