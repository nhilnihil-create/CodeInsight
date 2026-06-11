#include<stdio.h>
#include<string.h>
int main()
{
	int n,a,i,x=0;
	char s[10000];
	scanf("%d %s",&n,s);
	a=strlen(s);
	for(i=0;i<a;i++){
		x=s[i]-'A';
		x=(x+n)%26;
		printf("%c",x+'A');
	}
	printf("\n");
	return 0;
}
