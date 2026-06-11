#include <stdio.h>
#include <string.h>

int main ()
{
	char s[10];
	
	scanf("%s", s);
	
	(s[2] == s[3] && s[4] == s[5]) ? printf("Yes") : printf("No");
	
	return 0;
}