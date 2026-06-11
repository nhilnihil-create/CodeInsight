#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[11][10001],b[11],h,ans,w;
void check(){
	int sum=0,t[w]={};
	r(i,h){
		int x=0;
		r(j,w){
			if(b[i])t[j]+=!a[i][j];
			else t[j]+=a[i][j];
		}
	}
	r(i,w)sum+=max(t[i],h-t[i]);
	ans=max(ans,sum);
}
void dfs(int d){
	if(d==h)check();
	else{
		b[d]=0;
		dfs(d+1);
		b[d]=1;
		dfs(d+1);
	}
}
main(){
	while(cin>>h>>w,h){
		r(i,h)r(j,w)cin>>a[i][j];
		ans=0;
		dfs(0);
		cout<<ans<<endl;
	}
}