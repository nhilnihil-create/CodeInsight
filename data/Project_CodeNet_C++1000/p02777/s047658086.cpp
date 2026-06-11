#include <stdio.h>
#include <string.h>
int main()
{
	char color[15];
	char warna[15];
	char RGB [15];
	int A, B;
	
	scanf("%s %s", &color, &warna);
	scanf("%d %d", &A, &B);
	scanf("%s", &RGB);
	
	if (strcmp(RGB,warna)==0) printf("%d %d", A, B-1);
	if (strcmp(RGB,color)==0) printf("%d %d\n", A-1, B);
	
	return 0;
}