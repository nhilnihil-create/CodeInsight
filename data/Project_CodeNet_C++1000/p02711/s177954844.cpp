#include <stdio.h>
int main(){
	int a, b ,c, d, e, f;
	scanf("%d", &a);
	b= a/100;
	c= b*100;
	d= a-c;
	e= d%10;
	f= d/10;
	if (b==7){
		printf("Yes\n");
	}
	else if(e==7){
		printf("Yes\n");
	}
	else if(f==7){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}