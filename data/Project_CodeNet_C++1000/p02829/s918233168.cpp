#include <stdio.h>

int main (){
	
	int a,b,i;
	
	scanf("%d",&a);
	scanf("\n%d",&b);
	
	if(a==1 && b==2 || a==2 && b==1){
		printf("3\n");
	}else if (a==1 && b==3 || a==3 && b==1){
		printf("2\n");
	}else {
		printf("1\n");
	}
return 0;
}
