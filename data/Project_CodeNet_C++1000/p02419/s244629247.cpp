#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main()
{
	char W[100], M[10000];
	gets(W);
	int n, count=0;
	for (n = 0; n <= 100; n++)
		W[n] = tolower(W[n]);
	while (1)
	{
		scanf("%s", M);
		if (strcmp(M, "END_OF_TEXT") == 0)break;
		for (n = 0; n <= 10000; n++)M[n] = tolower(M[n]);
		if (strcmp(M, W) == 0)count++;
	}
	printf("%d\n", count);
	return 0;

}