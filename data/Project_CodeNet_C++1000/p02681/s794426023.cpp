#include <stdio.h>
#include <string.h>
char s[20],t[20];
int main(){
	int i,len;
	scanf("%s%s",s,t);
	len=strlen(s);
	for(i=0;i<len;i++)
		if(s[i]!=t[i])return 0*printf("No\n");
	return 0*printf("Yes\n");
}