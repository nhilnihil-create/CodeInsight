#include <stdio.h>


int main(){
	
	char strg1[104]="%s";
	char strg2[104]="%s";
	
	scanf("%s %s", strg1, strg2);
	printf("%s%s", strg2, strg1);
	
	return 0;
}