#include <stdio.h>

int main (){
	char num[10];
	scanf("%s", num);
	
	if(num[0]== '7'|| num[1]== '7'|| num[2]== '7'){
		printf("Yes\n");
	}else {
		printf("No\n");
	}

	return 0;
	
}