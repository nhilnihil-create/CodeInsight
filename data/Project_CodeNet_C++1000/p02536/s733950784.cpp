#include<bits/stdc++.h>
using namespace std; 
int const N=1e5+10;  
int f[N],vis[N],n,m;   
int find(int x){
	return  x==f[x]? x: f[x]=find(f[x]);  
} 
int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cin>>n>>m; 
	for(int i=1;i<=n;i++) 
		f[i]=i; 
	while (m--){ 
		int a,b;
		cin>>a>>b; 
		int fa=find(a); 
		int fb=find(b); 
		f[fa]=fb;  
	} 
	int ans=0; 
	for(int i=1;i<=n;i++){
		int father=find(i);  
		if(!vis[father]){ 
			vis[father]=1;  
			ans++; 
		} 
	}  
	cout<<ans-1<<'\n';   
	return 0; 
} 
