#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n,m;
	priority_queue<pair<ll,ll>>moto;
	priority_queue<ll>q;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		x*=-1;
		moto.push(make_pair(x,y));
	}
	ll ans=0;
	for(ll i=1;i<=m;i++){
		bool ch=true;
		while(ch&&moto.size()!=0){
			ch=false;
			ll nexd=moto.top().first;
			ll nexy=moto.top().second;
			nexd*=-1;
			if(nexd<=i){
				moto.pop();
				q.push(nexy);
				ch=true;
			}
		}
		if(q.size()!=0){
		ans+=q.top();
		q.pop();
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}