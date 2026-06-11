#include<iostream>
#include<cstdio>
using namespace std;
int f[15][10005];
int n,m;
int anss=0,ans=0;
void dfs(int q){
	if(q>n){
		//if(ans>anss)anss=ans;
		return ;
	}
	ans=0;
	for(int j=1;j<=m;j++){
		int count=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]==0)count++;
		}//cout<<"count "<<count<<endl;
		if(count>n/2)ans+=count;
		else ans+=n-count;
	}
	//cout<<"ans "<<ans<<endl;
	if(ans>anss)anss=ans;//cout<<anss<<endl;
	dfs(q+1);
	//ans=0;
	for(int j=1;j<=m;j++){
		f[q][j]=(f[q][j]+1)%2;
	}

	dfs(q+1);
	for(int j=1;j<=m;j++){
		f[q][j]=(f[q][j]+1)%2;
	}
}
int main(){
	while(scanf("%d%d",&n,&m)&&!(n==0)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&f[i][j]);
			}
		}
		dfs(1);
		cout<<anss<<endl;
	}
	return 0;
}