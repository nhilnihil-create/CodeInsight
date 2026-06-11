#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char s1[101];
	char p[101];
	char s2[202];
	gets(s1);
	gets(p);
	sprintf(s2, "%s%s", s1, s1);
	if (strstr(s2, p) != NULL) printf("Yes\n");
	else printf("No\n");
	return 0;
}