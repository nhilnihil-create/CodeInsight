#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll h,d,a;
	cin>>h>>d>>a;
	d*=2;
	vector<pair<ll,ll>>p;
	for(ll i=0;i<h;i++){
		ll x,y;
		cin>>x>>y;
		p.push_back(make_pair(x,y));
	}
	sort(p.begin(),p.end());
	queue<pair<ll,ll>>q;
	ll ans=0;
	ll tot=0;
	for(ll i=0;i<h;i++){
		ll nowx=p[i].first;
		ll nowh=p[i].second;
		if(q.size()!=0){
			ll nexx=q.front().first;
			ll nexa=q.front().second;
			while(nexx<nowx){
				tot-=nexa;
				q.pop();
				if(q.size()!=0){
					nexx=q.front().first;
					nexa=q.front().second;
				}
				else{
					break;
				}
			}
		}
		if(tot<nowh){
			ll nexa=nowh-tot;
			nexa=(nexa+a-1)/a;
			ans+=nexa;
			nexa*=a;
			tot+=nexa;
			q.push(make_pair(nowx+d,nexa));
		}
		//cout <<tot<<endl;
	}
	cout <<ans;
	return 0;
}