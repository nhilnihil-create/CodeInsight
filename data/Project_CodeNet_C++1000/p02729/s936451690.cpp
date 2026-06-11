#include <stdio.h>

int main (){
	
	int n,m,a,b;
	
	scanf("%d %d",&n,&m);
	
	a=(n*(n-1))/2;
	b=(m*(m-1))/2;	
	
	printf("%d\n",a+b);



return 0;
}