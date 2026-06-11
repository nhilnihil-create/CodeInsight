#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define inf 1e9
#define pb push_back
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> p[maxn],w,tmp;
int n,nw[maxn],vis[maxn],pre[maxn],fl;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++) {int x=read(); p[i].pb(x);}
		p[i].pb(inf);
	}
	int ans=0;
	for(int i=1;i<=n;i++) w.pb(i);
	while(1)
	{
		ans++; tmp.clear();
		//for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=0;i<w.size();i++)
		{
			int x=w[i],u=p[x][nw[x]];
			if(u==inf||vis[x]||vis[u]) continue;
			if(p[u][nw[u]]==x)
			{
				nw[x]++; nw[u]++;
				vis[x]=1; vis[u]=1;
				tmp.pb(x); tmp.pb(u);
			}
		}
		
		for(int i=0;i<tmp.size();i++) vis[tmp[i]]=0;
		w=tmp; if(w.size()==0) break;
	}
	int f=0;
	for(int i=1;i<=n;i++) if(nw[i]!=n-1) f=1;
	if(f==1) puts("-1"); else cout<<ans-1<<endl;
	return 0;
}