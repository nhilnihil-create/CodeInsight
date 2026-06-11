#include <stdio.h>
 
int main(void) {
	char s[10];
	scanf("%s", s);
 
	if (s[1] == 'B')
	{
		printf("ARC");
	}
	else
	{
		printf("ABC");
		return 0;
	}
}