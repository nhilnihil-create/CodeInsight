#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	char S[1000] = {};
	int a = 0;
	scanf("%s",S);
	for (int i = 0; S[i] != NULL; i++)
	{
		a++;
	}
	
	if (S[a-1] == 's')
	{
		printf("%ses", S);
	}
	else
	{
		printf("%ss", S);
	}
	return 0;
}