#include<bits/stdc++.h>
using namespace std;
int f[100001],n,m,q;
int getf(int u){
	if(u==f[u])return u;
	else return f[u]=getf(f[u]);
	}
int merge(int u,int v){
	int t1=getf(u);
	int t2=getf(v);
	if(t1!=t2){
		f[t2]=t1;
			}
}	
int main(){
	int v1,v2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		merge(v1,v2); 
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&v1,&v2);
		if(getf(v1)==getf(v2))printf("yes\n");
		else printf("no\n");
	}
}
