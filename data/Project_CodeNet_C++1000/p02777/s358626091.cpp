#include<stdio.h>
#include<string.h>

int main()
{
	char a[11], b[11], c[11];
	int d, e;
	scanf("%s %s\n", &a, &b);
	scanf("%d %d\n", &d, &e);
	scanf("%s", &c);
	
	if(strcmp(a, c) == 0) {
		printf("%d %d", d-1, e);
	}
	else if(strcmp(b, c) == 0){
		printf("%d %d", d, e-1);
	}
return 0;
}