#include <stdio.h>
#include <string.h>

int main(){
	char S[100];
	scanf("%s", &S);
	if(strcmp(S, "ABC") == 0){
		printf("ARC\n");
	}
	if(strcmp(S, "ARC") == 0){
		printf("ABC\n");
	}
	return 0;
}