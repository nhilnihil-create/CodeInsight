#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>>ch;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		ch.push_back(make_pair(x,y));
	}
	sort(ch.begin(),ch.end());
	reverse(ch.begin(),ch.end());
	ll ans=0;
	priority_queue<ll>q;
	for(ll i=1;i<=m;i++){
		bool c=true;
		while(ch.size()!=0&&c){
			c=false;
			pair<ll,ll>now=ch.back();
			if(i>=now.first){
				q.push(now.second);
				ch.pop_back();
				c=true;
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