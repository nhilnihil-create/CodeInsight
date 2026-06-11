#include <stdio.h>
#include <string.h>

int main(){
	
	char contest[5];
	scanf("%s", &contest);
	
	if(strcmp(contest, "ABC") == 0){
		printf("ARC");
	}else if(strcmp(contest,"ARC") == 0){
		printf("ABC");
	}
	return 0;
}