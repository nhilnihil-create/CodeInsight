#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
ll n,ans;
bool tr[20];
vector<pair<ll,ll>>ch[20];
void cal(){
	bool ch2=true;
	ll cnt=0;
	for(ll i=0;i<n;i++){
		if(tr[i]){
			cnt++;
			for(ll j=0;j<ch[i].size();j++){
				ll nexx=ch[i][j].first;
				ll nexy=ch[i][j].second;
				if(tr[nexx]!=nexy){
					ch2=false;
				}
			}
		}
	}
	if(ch2){
		ans=max(ans,cnt);
	}
}
void dep(ll now){
	if(now==n){
		cal();
		return ;
	}
	tr[now]=1;dep(now+1);
	tr[now]=0;dep(now+1);
}
int main() {
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		for(ll j=0;j<x;j++){
			ll now,y;
			cin>>now>>y;
			now--;
			ch[i].push_back(make_pair(now,y));
		}
	}
	dep(0);
	cout <<ans;
	// your code goes here
	return 0;
}