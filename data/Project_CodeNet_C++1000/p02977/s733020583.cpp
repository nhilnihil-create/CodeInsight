#include <cstdio>

int n;
int main(){
	scanf("%d",&n);
	if(n==1||(n&(-n))==n){puts("No");return 0;}
	puts("Yes");
	for(int i=2;i<n;i+=2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i,i,i+1,n+i+1,1,n+i,n+i+1);
	printf("%d %d\n",n+1,3);
	if(n%2==0)printf("%d %d\n%d %d\n",n+n-(n&(-n))+1,n,n+n,n&(-n));
}