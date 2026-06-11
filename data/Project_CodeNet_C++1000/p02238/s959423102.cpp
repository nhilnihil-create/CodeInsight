#include <cstdio>
#include <vector>
using namespace std;

int cnt=0;

void DFS(int k, vector<vector<int> >& V, vector<pair<int,int> >& time) {
	time[k].first=cnt++;
	for(int i=1; i<=(int)V[k].size(); ++i) {
		if(time[V[k][i]].first==-1) {
			DFS(V[k][i],V,time);
		}
	}
	time[k].second=cnt++;
	return;
}

int main() {
	int i,j;
	int n;
	int u,k;
	vector<vector<int> > V;
	vector<pair<int,int> > time;
	scanf("%d",&n);
	V.resize(n+1);
	V[0].resize(n+1);
	time.resize(n+1);
	for(i=1; i<=n; ++i) {
		V[0][i]=i;
		scanf("%d%d",&u,&k);
		V[u].resize(k);
		time[u]={-1,-1};
		for(j=1; j<=k; ++j) {
			scanf("%d",&V[u][j]);
		}
	}
	DFS(0,V,time);
	for(i=1; i<=n; ++i) {
		printf("%d %d %d\n",i,time[i].first,time[i].second);
	}
	return 0;
}