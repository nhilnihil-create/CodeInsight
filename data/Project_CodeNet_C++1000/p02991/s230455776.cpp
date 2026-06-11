#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool f[314514];
int main(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>>v(314514);
	vector<ll>dis(314514,1e9);
	ll p=100000;
	for(int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		v[a].push_back(b+p);
		v[a+p].push_back(b+2*p);
		v[a+2*p].push_back(b);
	}
	ll s,t;
	cin>>s>>t;
	dis[s]=0;
	f[s]=1;
	queue<P>que;
	que.push({s,0});
	while(!que.empty()){
		P x=que.front();
		que.pop();
		for(ll num:v[x.first]){
			if(f[num])continue;
			f[num]=1;
			que.push({num,x.second+1});
			dis[num]=x.second+1;
		}
	}
	if(dis[t]==1e9)cout<<-1;
	else cout<<dis[t]/3;
	return 0;
}
