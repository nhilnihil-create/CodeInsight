#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n<=2)return puts("No"),0;
	int tmp=1;while(tmp<<1<=n)tmp<<=1;
	if(tmp==n)return puts("No"),0;
	
	puts("Yes");
	printf("1 2\n");printf("2 3\n");
	printf("3 %d\n",n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	
	for(int i=4;i<n;i+=2){
		printf("%d %d\n",n+1,i);
		printf("%d %d\n",n+1,i+1);
		printf("%d %d\n",i,i+1+n);
		printf("%d %d\n",i+1,i+n);
	}
	if(n%2==0){
		printf("%d %d\n",tmp,n);
		printf("%d %d\n",n^tmp^1,2*n);
	}
	return 0;
}
