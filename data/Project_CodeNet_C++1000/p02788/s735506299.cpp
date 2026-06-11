#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,d,a;
	cin>>h>>d>>a;
	d*=2;
	vector<pair<ll,ll>>ch;
	for(ll i=0;i<h;i++){
		ll x,y;
		cin>>x>>y;
		ch.push_back(make_pair(x,y));
	}
	sort(ch.begin(),ch.end());
	queue<pair<ll,ll>>q;
	ll at=0;
	ll cnt=0;
	for(ll i=0;i<h;i++){
		ll nowx=ch[i].first;
		if(q.size()!=0){
			ll nexx=q.front().first;
			while(nowx>nexx&&q.size()!=0){
				ll nexa=q.front().second;
				at-=nexa;
				q.pop();
				if(q.size()!=0){
					nexx=q.front().first;
				}
			}
		}
		ll nowh=ch[i].second;
		if(at<nowh){
			ll tu=(nowh-at+a-1)/a;
			cnt+=tu;
			at+=tu*a;
			q.push(make_pair(nowx+d,tu*a));
		}
	}
	cout <<cnt;
}