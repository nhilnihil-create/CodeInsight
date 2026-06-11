#include <stdio.h>

int main(){
	char huruf;
	scanf("%c",&huruf);
	if (huruf >=65 && huruf <=90){
		printf("A\n");
	}
	else{
		printf("a");
	}
	return 0;
}