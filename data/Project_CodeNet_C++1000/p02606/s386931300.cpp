#include <stdio.h>
int main(){
	int a, b, c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(b/c*c-(a+c-1)/c*c)/c+1);
	
	return 0;
}