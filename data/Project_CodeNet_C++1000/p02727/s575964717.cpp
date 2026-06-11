#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007


int main() {
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<ll>p,q,r;
	for(ll i=0;i<a;i++){
		ll now;
		cin>>now;
		p.push_back(now);
	}
	sort(p.begin(),p.end());
	for(ll i=0;i<x;i++){
		ll now=p[a-i-1];
		r.push_back(now);
	}
	for(ll i=0;i<b;i++){
		ll now;
		cin>>now;
		q.push_back(now);
	}
	sort(q.begin(),q.end());
	for(ll i=0;i<y;i++){
		ll now=q[b-i-1];
		r.push_back(now);
	}	
	for(ll i=0;i<c;i++){
		ll now;
		cin>>now;
		r.push_back(now);
	}
	sort(r.begin(),r.end());
	reverse(r.begin(),r.end());
	ll ans=0;
	for(ll i=0;i<x+y;i++){
		ans+=r[i];
	}
	cout <<ans;
	return 0;
}