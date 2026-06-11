#include <stdio.h>

int main(){
	
	int h, a;
	scanf("%d%d", &h, &a);
	getchar();
	
	int att = h % a;
	int num1 = h / a;
	int num2 = h / a+1; 
	
	(att == 0)? printf("%d\n", num1) : printf("%d\n", num2);
		
	return 0;
}