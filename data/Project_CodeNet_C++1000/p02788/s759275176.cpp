#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,d,a;
	cin>>n>>d>>a;
	vector<pair<ll,ll>>ch;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		ch.push_back(make_pair(x,y));
	}
	sort(ch.begin(),ch.end());
	queue<pair<ll,ll>>q;
	ll ans=0;
	ll dm=0;
	for(ll i=0;i<n;i++){
		ll nowx=ch[i].first;
		while(q.size()!=0&&q.front().first<nowx){
			dm-=q.front().second;
			q.pop();
		}
		ch[i].second-=dm;
		if(ch[i].second>0){
			ans+=(ch[i].second+a-1)/a;
			ll dm1=((ch[i].second+a-1)/a)*a;
			dm+=dm1;
			q.push(make_pair(nowx+2*d,dm1));
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}