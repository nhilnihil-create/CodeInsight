#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int a[10][10];
char x;
int h[10],w[10];
void dfs(int u){
	if(u==n+m+1){
//		for(int i=1;i<=n;++i)cout<<h[i]<<" ";
//			for(int j=1;j<=m;++j)cout<<w[j]<<" ";cout<<endl;
		int s=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if(h[i]||w[j]) continue;
				if(a[i][j]) s++;
			}
//		cout<<s<<endl;
		if(s==k) ans++;
		return;
	}
	if(u<=n){
		dfs(u+1);
		h[u]=1;
		dfs(u+1);
		h[u]=0;
	}
	else{
		dfs(u+1);
		w[u-n]=1;
		dfs(u+1);
		w[u-n]=0;
	}
}
int main(){
//	freopen("x.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>x;
			if(x=='#') a[i][j]=1;//cout<<x<<" "<<a[i][j]<<endl;
		}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}