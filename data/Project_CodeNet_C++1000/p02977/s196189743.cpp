#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(__builtin_popcount(n)==1){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(n&1){
		for(int i=2;i<=n;i+=2){
			printf("%d %d\n",1,i);
			printf("%d %d\n",1,i+n+1);
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n+1,3);
	}else{
		for(int i=2;i<=n-1;i+=2){
			printf("%d %d\n",1,i);
			printf("%d %d\n",1,i+n+1);
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n+1,3);
		int pos=-1;
		for(int i=0;i<30;++i)if(n>>i&1){
			pos=1<<i;
			break;
		}
		printf("%d %d\n",n,pos);
		printf("%d %d\n",n+n,n-pos+n+1);
	}
	return 0;
}