#include<cstdio>
int main()
{
	char s[3];
	int i;
	for(i=0;i<3;i++) scanf("%c",&s[i]);
	if(s[1]=='B') printf("ARC\n");
	else printf("ABC\n");
	return 0;
}
