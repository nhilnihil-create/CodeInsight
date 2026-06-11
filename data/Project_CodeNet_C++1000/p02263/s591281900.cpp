#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	long stack[100] = { 0 }, idx = 0;
	char input[1000],*elem;

	gets(input);
	elem = strtok(input, " ");
	while(elem!=NULL){
		if (elem[0] == '+'){
			stack[idx - 1] += stack[idx--];
		}
		else if (elem[0] == '-'){
			stack[idx - 1] -= stack[idx--];
		}
		else if (elem[0] == '*'){
			stack[idx - 1] *= stack[idx--];
		}else{
			stack[++idx] = atol(elem);
		}
		elem = strtok(NULL, " ");
	}
	printf("%d\n", stack[idx]);
	return 0;
}