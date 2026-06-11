#include <stdio.h>
#include <string.h>
char s[110];
int main(){
	int k,n,i;
	scanf("%d%s",&k,s+1);
	n=strlen(s+1);
	if(n<=k)printf("%s\n",s+1);
	else{
		for(i=1;i<=k;i++)printf("%c",s[i]);
		printf("...\n");
	}
}
 