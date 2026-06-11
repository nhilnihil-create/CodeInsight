#include "stdio.h"

#define ALP_SIZE 26

int main()
{
	int A[ALP_SIZE];
	int i;
	char ch;

	for (i = 0; i < ALP_SIZE; i++) A[i] = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= 0x41 && ch <= 0x5A || ch >= 0x61 && ch <= 0x7A) A[(ch & 0x1F) - 1]++;
	}

	for (i = 0; i < ALP_SIZE; i++) printf("%c : %d\n",0x61 + i, A[i]); 

	return 0;
}