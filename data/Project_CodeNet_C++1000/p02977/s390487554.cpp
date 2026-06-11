#include<cstdio>
int n;
int main(){
	scanf("%d",&n); if(n<=2||!(n&(n-1))){puts("No");return 0;}puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3); 
	for(int i=4;i<n;i+=2)printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,i+1,i,n+1,n+1,n+i+1,n+i+1,n+i);
	if(!(n&1))printf("%d %d\n%d %d\n",n,n-(n&-n),n+n,((n&-n)==2?0:n)+(n&-n)+1);
}