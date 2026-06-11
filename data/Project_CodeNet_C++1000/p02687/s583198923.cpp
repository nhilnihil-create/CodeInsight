#include <stdio.h>
int main() {
	char s[3+1];
	scanf("%s",&s);
	
	if (s[1] == 'B')
	{
		printf("ARC\n");
	}
	else if (s[1] == 'R')
	{
		printf("ABC\n");
	}
	
	return 0;
}
