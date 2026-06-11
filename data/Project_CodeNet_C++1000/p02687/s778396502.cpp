#include <stdio.h>

int main (){
	char str[5];
	
	scanf ("%s", &str);
	if  (str[1] == 'B'){
		printf ("ARC");
	}
	else if (str[1] == 'R'){
		printf ("ABC");
	}
	
	
	return 0;
}