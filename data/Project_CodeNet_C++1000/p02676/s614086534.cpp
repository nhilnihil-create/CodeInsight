#include <stdio.h>
#include <string.h>

int main(){
	int a,b,x,y;
	char c[100];
	scanf("%d", &a);
	getchar();
	scanf("%[^\n]", &c);
	
	x=strlen(c);
	y=x-a;
	if(x>a){
		for(int i=0;i<a;i++){
			printf("%c", c[i]);
		}
		puts("...");
	}
	
	else{
		for(int i=0;i<x;i++){
			printf("%c", c[i]);		}
	}
	
	return 0;
}