#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n;
vector<pair<ll,ll>>ch[16];
bool man[16];
ll ans;
void cal(){
	ll cnt=0;
	for(ll i=0;i<n;i++){
		if(man[i]==0){
			continue;
		}
		cnt++;
		for(ll j=0;j<ch[i].size();j++){
			ll next=ch[i][j].first;
			if(ch[i][j].second!=man[next]){
				return;
			}
		}
	}
	ans=max(ans,cnt);
}
void dep(ll now){
	if(now==n){
		cal();
		return;
	}
	man[now]=0;dep(now+1);
	man[now]=1;dep(now+1);
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
	// your code goes here
	return 0;
}