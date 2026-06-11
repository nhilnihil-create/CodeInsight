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
		ll x,h;
		cin>>x>>h;
		h=(h+a-1)/a;
		ch.push_back(make_pair(x,h));
	}
	sort(ch.begin(),ch.end());
	ll nowx=ch[0].first+2*d;
	ll ans=0;
	ans+=ch[0].second;
	ll nowb=ch[0].second;
	queue<pair<ll,ll>>q;
	q.push(make_pair(nowx,nowb));
	for(ll i=1;i<n;i++){
//		cout <<ans<<" "<<nowb<<endl;
		ll nexx=ch[i].first;
		if(q.size()!=0){
			ll nowx=q.front().first;
			while(nowx<nexx){
				nowb-=q.front().second;
				q.pop();
				if(q.size()==0){
					break;
				}
				nowx=q.front().first;
			}
		}
		ll nexb=ch[i].second;
		if(nexb>nowb){
			ans+=nexb-nowb;
			q.push(make_pair(nexx+2*d,nexb-nowb));
			nowb=nexb;			
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}