#include <stdio.h>
 
int main() {
	char str[4];
	scanf("%s", str);
	if(str[1] == 'B'){
		puts("ARC");		
	}else if(str[1] == 'R'){
		puts("ABC");
	}
	
	
	return 0;
}