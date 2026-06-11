#include<stdio.h>
#include<string.h>
int main()
{
	char s[11];
	char t[11];
	char u[11];
	int a,b;
	scanf("%s %s\n%d %d\n%s",s,t,&a,&b,u);
	if(strcmp(u,s)==0){
	printf("%d %d\n",a-1,b);
    }
	else if(strcmp(u,t)==0){
	printf("%d %d\n",a,b-1 );
    } 
	return 0;
}