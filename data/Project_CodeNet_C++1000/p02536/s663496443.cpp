#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10; 
int f[N];
int get(int x){
	if(f[x]!=x)f[x]=get(f[x]);
	return f[x];
} 
int main(){
	int n,m,x,y,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		int f1=get(x),f2=get(y);
		if(f1!=f2){
			ans++,f[f1]=f2;
		}
	}
	printf("%d\n",n-1-ans);
}