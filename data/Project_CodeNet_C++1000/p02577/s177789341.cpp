#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000000];
	long long int i, j, p = 0, a, k;
 scanf("%s",s);
	a = strlen(s);//printf("%d",a);
	for (i = 0; i < a; i++)
	{
		p = p + (s[i] - '0');
		p = p % 9;
	}
	if (p % 9 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
