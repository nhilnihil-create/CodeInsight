#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n;
vector<pair<ll,ll>>ch[16];
ll ans;
ll tr[16];
void cal(){
	ll CH=1;
	for(ll i=0;i<n;i++){
		if(tr[i]!=1){
			continue;
		}
		for(ll j=0;j<ch[i].size();j++){
			ll now=ch[i][j].first;
			ll so=ch[i][j].second;
			if(tr[now]!=so){
				CH=0;
			}
		}
	}
	if(CH==1){
		ll cnt=0;
		for(ll i=0;i<n;i++){
			if(tr[i]==1){
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
}
void dep(ll now){
	if(now==n){
		cal();
		return ;
	}
	tr[now]=0;dep(now+1);
	tr[now]=1;dep(now+1);
}
int main() {
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		for(ll j=0;j<now;j++){
			ll x,y;
			cin>>x>>y;
			x--;
			ch[i].push_back(make_pair(x,y));
		}
	}
	dep(0);
	cout <<ans;
	return 0;
}