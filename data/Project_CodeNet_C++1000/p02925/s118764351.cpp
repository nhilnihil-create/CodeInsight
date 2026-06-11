#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int n,x,pre,eg,ans,cnt,hd[MAXN],vis[MAXN],in[MAXN],tmp[MAXN],ver[2*MAXN],nx[2*MAXN];
queue <int> q;
int hs (int x,int y) {
	if (x>y) {swap(x,y);}
	return (x-1)*n+y;
}
void add_edge (int x,int y) {
	ver[++eg]=y;
	nx[eg]=hd[x];
	hd[x]=eg;
	in[y]++;
	return;
}
int main () {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n-1;j++) {
			scanf("%d",&x);
			if (j>1) {add_edge(hs(i,pre),hs(i,x));}
			pre=x;
		}
	}
	for (int i=1;i<=MAXN-10;i++) {
		if (!in[i]) {cnt++,q.push(i);}
	}
	while (!q.empty()) {
		int cur=0;
		while (!q.empty()) {
			tmp[++cur]=q.front();
			q.pop();
		}
		for (int i=1;i<=cur;i++) {
			for (int j=hd[tmp[i]];j;j=nx[j]) {
				if (--in[ver[j]]==0) {
					q.push(ver[j]);
					cnt++;
				}
			}
		}
		ans++;
	}
	if (cnt!=MAXN-10) {printf("-1\n");} 
	else {printf("%d\n",ans);}
	return 0;
}