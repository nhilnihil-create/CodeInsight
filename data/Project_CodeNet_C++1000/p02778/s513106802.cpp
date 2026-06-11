#include<stdio.h>
#include<string.h>
int main(void)
{
	int len,i;
	char s[101],x;
	scanf("%s",s);
	len=strlen(s);
	x='x';
	for(i=0;i<len;i++){
		printf("%c",x);
	}
	return 0;
}