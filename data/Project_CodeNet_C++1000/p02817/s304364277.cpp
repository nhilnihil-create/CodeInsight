#include <stdio.h>
#include <string.h>

int main()
{
	char S[255],T[255];
	scanf("%s%s",S,T);
	strcat(T,S);
	printf("%s",T);
	
	return 0;
}