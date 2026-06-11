#include <stdio.h>
#include <string.h>

int main() {
	
	char kata1[10];
	scanf("%s",kata1);
	if(kata1[0] == 'A' && kata1[1] == 'B' && kata1[2] == 'C'){
		printf("ARC\n");
	}else
	{
		printf("ABC\n");
	}
	
	return 0; 
}