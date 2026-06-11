#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+23;

vector<int> g[maxn];
int n;

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	ll ans=0,now=0;
	for(int i=n;i;i--){
		now+=n-i+1;
		auto it=lower_bound(g[i].begin(),g[i].end(),i);
		while(it!=g[i].end()){
			now-=n-*it+1;	
			it++;
		}
		ans+=now;
	}
	printf("%lld",ans);
}