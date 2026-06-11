#include <stdio.h>
 
int main () {
	char num[4];
	scanf("%s", &num);
	
	if (num[0] == '7' || num[1] == '7' || num[2] == '7') {
		printf("Yes");
	}
	else {
		printf("No");
	}
	
	
	return 0;
}