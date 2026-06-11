#include <stdio.h>

int main() {
	
	int input;
	
	scanf("%d", &input);
	
	if (input/100 == 7){
		puts("Yes");
	}else if ((input - (input/100)*100)/10 == 7){
		puts("Yes");
	}else if ((input - (input/10)*10) == 7){
		puts("Yes");
	}else{
		puts("No");
	}
	
	return 0;
}
