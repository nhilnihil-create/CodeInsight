#include <stdio.h>
int main(){
	int a,b,c,k,sum=0;
	scanf("%d%d%d%d",&a,&b,&c,&k);
	if(k<=a)return 0*printf("%d\n",k);
	if(k>a)sum+=a,k-=a;
	if(k<=b)return 0*printf("%d\n",sum);
	if(k>b)sum+=0,k-=b;
	return 0*printf("%d\n",sum-k);
	return 0;
}