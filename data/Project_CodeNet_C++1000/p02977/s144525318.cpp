#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
inline int read(){
	int ans=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<3)+(ans<<1)+(c-'0');c=getchar();}
	return ans*k;
}
int main(){
	n=read();
	if(!(n&(n-1))){
		printf("No");
		return 0;
	}
	printf("Yes\n");
	if(n%4==0){
		for(register int i=1;i<n-1;i++){
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n-1,n+1);
		printf("%d %d\n",n,(n&(-n))+1);
		printf("%d %d\n",n+n,n+(n^(n&(-n))));
		return 0;
	}
	if(n%4==1){
		for(register int i=1;i<n-2;i++){
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n-2,n+1);
		printf("%d %d\n",n-1,1);
		printf("%d %d\n",n,n-1);
		printf("%d %d\n",n+n,1);
		printf("%d %d\n",n+n-1,n+n);
		return 0;
	}
	if(n%4==2){
		for(register int i=1;i<n-3;i++){
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n-3,n+1);
		printf("%d %d\n",n-2,1);
		printf("%d %d\n",n-1,n-2);
		printf("%d %d\n",n+n-1,1);
		printf("%d %d\n",n+n-2,n+n-1);
		printf("%d %d\n",n,n+n-1);
		printf("%d %d\n",n+n,2);
		return 0;
	}
	if(n%4==3){
		for(register int i=1;i<n+n;i++)printf("%d %d\n",i,i+1);
		return 0;
	}
	return 0;
} 