#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int Maxn=1e5;
const ll Mod=1000000007;

int N,K;
vector<int> G[Maxn+5];
void addedge(int u,int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

long long ans;

long long DFS(int u,int fa,int dep) {
	int tmp=K-min(dep,2);
	for(int i=0;i<(int)G[u].size();i++) {
		int v=G[u][i];
		if(v==fa)continue;
		if(DFS(v,u,dep+1)==0)
			return 0;
		ans=ans*tmp%Mod;
		tmp--;
	}
	return ans;
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d %d",&N,&K);
	for(int i=1;i<N;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
	}
	ans=K;
	printf("%lld\n",DFS(1,-1,1));
	return 0;
}
