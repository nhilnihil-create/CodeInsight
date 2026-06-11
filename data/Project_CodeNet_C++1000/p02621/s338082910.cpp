#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	int digit[3]={a, a*a, a*a*a};
	int sum=0;
	sum= digit[0] + digit[1] + digit[2];
	
	printf("%d\n", sum);
	
	return 0;
}