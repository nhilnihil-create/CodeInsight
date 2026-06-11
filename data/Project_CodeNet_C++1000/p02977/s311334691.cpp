//蓝莲花__ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,f[N],g[N];
void check(int x){
	int sum=0;
	while(x)sum+=(x&1),x>>=1;
	if(sum==1){printf("No\n");exit(0);}
	printf("Yes\n");
	f[0]=1;for(int i=1;i<=30;++i)f[i]=f[i-1]<<1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	check(n);
	
	int now=0;while(f[now+1]-1<=n)++now;
	int m=f[now]-1;
	
	for(int i=1;i<=m-1;++i)printf("%d %d\n",i,i+1),g[i]=i;
	printf("%d %d\n",m,1+n);
	for(int i=1;i<=m-1;++i)printf("%d %d\n",i+n,i+1+n),g[i+m]=i+n;
	
	int res=n-m;
	if(res==0)return 0;
	printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,m+1,m+1,m+2,1,m+2+n,m+2+n,m+1+n);
	if(res==2)return 0;
	printf("%d %d\n%d %d\n",m+2+n,m+3,2,m+3+n);
	if(res==3)return 0;
	for(int i=m+4;i<=n;++i)printf("%d %d\n%d %d\n",i-1+n,i,g[i-m-1],i+n);
	return 0;
}/*
26
1 2
2 3
3 4
4 5
5 6
6 7
7 14
14 15
15 16
16 17
17 18
18 19
19 20
1 8
8 9
1 22
22 21
22 10
2 23
23 11
3 24
24 12
4 25
25 13
5 26
*/