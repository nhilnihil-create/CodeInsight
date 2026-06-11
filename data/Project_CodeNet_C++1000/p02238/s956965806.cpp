#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
int G[101][101];
bool used[101];
int f[101],s[101];
int cnt=0;
void dfs(int now){
	cnt++;
	s[now]=cnt;
	used[now]=1;
	for(int i=1;i<=100;i++){
	if(G[now][i]&&used[i]==0)dfs(i);
	}
	cnt++;
	f[now]=cnt;
}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
int u,k,v;
cin>>u>>k;
for(int j=0;j<k;j++){
cin>>v;
G[u][v]=1;
}
}
dfs(1);
while(true){
int f=1,next=0;

	for(int j=1;j<=n;j++){
		if(used[j]==0){
		f=0,next=j;
		break;
		}
	}

if(f)break;
else dfs(next);
}
for(int i=1;i<=n;i++){
	printf("%d %d %d\n",i,s[i],f[i]);
}
return 0;
}