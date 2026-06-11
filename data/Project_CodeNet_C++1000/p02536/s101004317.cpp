#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 ;
int n,m;
int f[N];
int getf(int v){
	if(f[v]==v){
		return f[v];
	}else{
		f[v]=getf(f[v]);
		return  f[v];
	}
}
int merge(int u,int v){
	int t1=getf(u);
	int t2=getf(v);
	if(t1!=t2){
		f[t2]=t1;
		return 1;
	}
	return 0;
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++) f[i]=i;
	int u,v,sum=0;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		if(merge(u,v)) sum++;
	}	
	int ans=n-1-sum;
	cout<<ans;
	return 0; 
}
