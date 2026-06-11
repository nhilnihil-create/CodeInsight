#include <stdio.h>

int main (){
	
	int n,m,a,b;
	
	scanf("%d %d",&n,&m);
	
	if(n==1 && m==1){
		puts("0");
	}else{
		n--;
		m--;
		a=(n*(n+1))/2;
		b=(m*(m+1))/2;
	printf("%d\n",a+b);
}

return 0;
}

