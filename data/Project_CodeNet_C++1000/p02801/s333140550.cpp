#include <stdio.h>
int main()
{
	char huruf;
	scanf("%c", &huruf);
	if (huruf>=97 && huruf<=122) printf("%c\n", huruf+1);
	
	return 0;
}