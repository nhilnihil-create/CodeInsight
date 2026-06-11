#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,q,ans,a[52],b[52],c[52],d[52],f[52];
inline void dfs(re int x){
	if(x>n){
		re int sum=0;
		for(re int i=1;i<=q;++i){
			if(f[b[i]]-f[a[i]]==c[i])sum+=d[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(re int i=f[x-1];i<=m;++i){
		f[x]=i;
		dfs(x+1);
	}
}
signed main(){
	n=read(),m=read(),q=read();
	for(re int i=1;i<=q;++i){
		a[i]=read();
		b[i]=read();
		c[i]=read();
		d[i]=read();
	}
	f[0]=1;
	dfs(1);
	printf("%d",ans);
}