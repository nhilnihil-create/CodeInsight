#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
const int MX = 100001;
int n,a,b,m,ans[MX];
vector<P> G[MX];
void dfs(int now, int parent, int pcolor){
	int ncolor = 1;
	for(P nowx: G[now]){
		if(nowx.first != parent){
			if(ncolor == pcolor) ncolor++;
			ans[nowx.second] = ncolor;
			dfs(nowx.first,now,ncolor);
			ncolor++;
		}
  	}
}
int main(){
	scanf("%d", &n);
	rep(i,n-1){
		scanf("%d%d", &a, &b); a--; b--;
		G[a].push_back(P(b,i));
		G[b].push_back(P(a,i));
	}
	rep(i,n) m = max(m,(int)G[i].size());
	dfs(0,0,0);
	printf("%d\n", m);
	rep(i,n-1) printf("%d\n", ans[i]);
}
