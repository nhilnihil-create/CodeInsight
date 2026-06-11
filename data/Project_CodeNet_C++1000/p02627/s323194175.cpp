#include <stdio.h>

int main(){
	char huruf;
	scanf("%c",&huruf);
	if (huruf >='A' && huruf <='Z'){
		printf("A\n");
	}
	else{
		printf("a");
	}
	return 0;
}