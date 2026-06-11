#include<stdio.h>
#include<string.h>

int main(){
int a,b;
char aName[15], bName[15], cName[15];
scanf("%s%s", aName, bName);
scanf("%d%d", &a, &b);
getchar();
scanf("%s", cName);
if(strcmp(cName,aName)==0)printf("%d %d\n", a-1, b);
else printf("%d %d\n", a, b-1);
	return 0;
}