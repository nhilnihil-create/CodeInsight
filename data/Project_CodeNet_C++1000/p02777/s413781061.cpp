#include<stdio.h>
#include<string.h>

int main(){
	char a[15], b[15], c[15];
	int d,e;
	
	scanf("%s %s\n%d %d\n%s",&a,&b,&d,&e,&c);
	if(strcmp(a,c)==0){
		printf("%d %d", d-1,e);
	}	
	else if(strcmp(b,c)==0){
		printf("%d %d",d,e-1);
	}
	return 0;
}