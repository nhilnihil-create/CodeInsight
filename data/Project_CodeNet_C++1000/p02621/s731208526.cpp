#include <stdio.h>

int main () {
	int input,jumlah;
	scanf("%d", &input);
	
	jumlah=input + (input*input) +(input*input*input);
	
	printf("%d\n", jumlah);
	
	return 0;
}