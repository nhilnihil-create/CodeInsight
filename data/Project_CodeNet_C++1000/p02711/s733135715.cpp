#include<stdio.h>
#include<string.h>
int main(){
	char x[10];
	scanf("%s",&x);
	int ada  = 0;
	for(int i=0;i<strlen(x);i++)
		if(x[i]=='7')
			ada=1;
	if(ada==1)
		printf("Yes");
	else
		printf("No");
	printf("\n");
}