#include <stdio.h>


int main(){
	char stg[5];
	scanf("%s", stg);
	
	if(stg[1] == 'B'){
		printf("ARC");
	}
	else if(stg[1] == 'R'){
		printf("ABC");
	}
	return 0;
}