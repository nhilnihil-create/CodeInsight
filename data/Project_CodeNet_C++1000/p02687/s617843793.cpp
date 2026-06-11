#include <stdio.h>
int main(){
	
	char num[10];
	scanf("%s" , num);
	
	if (num[1] == 'B'){
		num[1] = 'R';
		printf("%s" , num);
	}
	else{
		num[1] = 'B';
		printf("%s" , num);
	}
	return 0;
}