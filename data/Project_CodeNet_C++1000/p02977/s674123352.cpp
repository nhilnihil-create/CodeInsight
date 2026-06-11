#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=7;
const int INF=1e9+7;
int n;

int main(){
	scanf("%d",&n);
	int m=n;
	while(m%2==0)m/=2;
	if(m==1){
		puts("No");
		return 0;
	}
	puts("Yes");
	puts("1 2");
	puts("2 3");
	printf("3 %d\n",n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	for(int i=5;i<=n;i+=2){
		printf("%d %d\n",n+i-1,i);
		printf("%d %d\n",i-1,n+i);
		printf("1 %d\n",i);
		printf("1 %d\n",i-1);
	}
	if(n%2==0){
		if(n%4==0){
			int lw=n&(-n);
			printf("%d %d\n",n,n-lw);
			printf("%d %d\n",n+n,lw^1);
		}
		else{
			printf("%d %d\n",n,n-1);
			printf("%d %d\n",n+n,2);
		}
	}
	return 0;
}
