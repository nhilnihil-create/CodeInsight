#include<stdio.h>
#include<string.h>
int main()
{
	char s[11];
	char t[11];
	char u[11];
	int x,y;
	scanf("%s %s",&s,&t);
	scanf("%d %d",&x,&y);
	scanf("%s",&u);
	if(strcmp(u,s) == 0){
		printf("%d %d",x-1,y );
}
	else if (strcmp(u,t) == 0) {
		printf("%d %d", x, y - 1);	
}
	return 0;
}