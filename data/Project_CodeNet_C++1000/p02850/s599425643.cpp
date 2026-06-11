#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

using Edge=pair<ll,ll>;
using Graph = vector<vector<Edge>>;

int main(){
	ll n; cin >> n;
	Graph G(n);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(mp(b,i));
		G[b].push_back(mp(a,i));
	}
	ll maxcolor=0;
	for(ll i=0;i<n;i++) maxcolor=max(maxcolor,(ll)G[i].size());

	vector<ll> res(n-1,-1);
	vector<ll> dist(n,-1);
	queue<pair<ll,ll>> que;
	que.push(mp(0,-1));
	dist[0]=0;
	while(!que.empty()){
		auto p=que.front();que.pop();
		ll v=p.fi,c=p.se;
		ll color=1;
		if(color==c) color++;
		for(auto e:G[v]){
			if(dist[e.fi]==-1){
				dist[e.fi]=dist[v]+1;
				que.push(mp(e.first,color));
				res[e.se]=color;
				color++;
				if(color==c) color++;
			}
		}
	}
	cout << maxcolor << endl;
	for(ll i=0;i<n-1;i++) cout << res[i] << endl;
}
