#include <stdio.h>

int main (){
	
	char kata[1000];
	scanf ("%s", &kata);
	
	if (kata[0] == 'A' && kata [1] == 'B' && kata[2] == 'C'){
		printf ("%s", "ARC");
	}	
	else{
		printf ("ABC");
	}
	
	return 0;
}