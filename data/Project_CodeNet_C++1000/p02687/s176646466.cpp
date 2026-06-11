#include <stdio.h>
#include <string.h>

int main() {
	char con[4];
	
	scanf("%s", con);
	if(strcmp(con, "ABC") == 0) {
		printf("ARC");
		
		return 0;
	}
	printf("ABC");
	
	return 0;
}