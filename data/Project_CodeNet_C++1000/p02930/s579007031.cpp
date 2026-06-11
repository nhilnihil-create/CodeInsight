#include<bits/stdc++.h>
#define ci const int&
using namespace std;
int n,e[510][510],len,p;
int p2(int x){
	int tmp=1;
	while(!(x&1))++tmp,x>>=1;
	return tmp;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n>>1);++i)for(int j=1;j<=n;++j)e[j][(j+i-1)%n+1]=p2((j-1)^((j+i-1)%n));
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)printf("%d%c",max(e[i][j],e[j][i])," \n"[j==n]);
	return 0;
}