#include <stdio.h>
int main()
{
	int i, j, n, m;
	char str[10];
	scanf("%s", str);
	for (i=0; i<3; i++)
	{
		if (str[i] == str[i+1])
		{
			printf("Bad");
			return 0;
		}
		    
	}
	printf("Good");
	return 0;
}