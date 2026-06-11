#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef long long ll;
struct Edge{
	int v,nxt;
}e[maxn<<1];
int head[maxn],cnt_e;
void add(int u,int v){
	e[++cnt_e].v=v;
	e[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}
int n;
ll fa[maxn];
void dfs(int x){
	for(int i=head[x];i;i=e[i].nxt){
		int v=e[i].v; if(v==fa[x]) continue;
		fa[v]=x; dfs(v);
	}
}
int main(){
	//freopen("data.in","r",stdin);
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1);
	ll ans=n;
	for(int i=2;i<=n;i++){
		//cout<<"i= "<<i<<" "<<fa[i]<<endl;
		if(fa[i]>i){
			ans=ans+(fa[i]-i)*i;
		}
		else{
			ans=ans+(i-fa[i])*(n-i+1);
		}
	}
	cout<<ans<<endl;
}