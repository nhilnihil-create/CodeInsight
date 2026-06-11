#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e10;
const double PI=acos(-1.0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> path,visited(n+1),dist(n+1);
	int cur=1;
	while(true){
		visited[cur]=true;
		path.push_back(cur);
		if(!visited[a[cur]]) dist[a[cur]]=1+dist[cur],cur=a[cur];
		else break;
	}
	if(k<dist[a[cur]]){
		cout<<path[k];
		return 0;
	}
	k-=dist[a[cur]];
	k%=(dist[cur]-dist[a[cur]]+1);
	cout<<path[dist[a[cur]]+k];
}
