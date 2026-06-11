#include<stdio.h>
#include<string.h>
int main()
{
	char str[255];
	
	scanf("%s", str);
	getchar();
	
	if(strcmp(str,"ABC") == 0){
		printf("ARC\n");
	}else{
		printf("ABC\n");
		
	}
}