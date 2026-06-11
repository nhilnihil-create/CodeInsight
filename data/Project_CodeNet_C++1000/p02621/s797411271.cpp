#include <stdio.h>
int main (){
	int input;
	scanf("%d", &input);
	printf("%d\n", input + (input * input) + (input * input * input));
	
	return 0;
}