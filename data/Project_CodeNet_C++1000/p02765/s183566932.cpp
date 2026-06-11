#include <stdio.h>

int main (){
	
	int n,r,a,b;
	
	scanf("%d %d",&n,&r);
	
	if(n<=10){
		a=100 * (10-n);
		b=r + a;
		printf("%d\n",b);
	}else{
		printf("%d\n",r);
	}

return 0;
}
