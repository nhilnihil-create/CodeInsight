#include <stdio.h>
#include <string.h>

int main (){
	
	int a,b;
	char s [15],t[15],u[15];
	
	scanf("%s %s",&s,&t);
	scanf("%d %d",&a,&b);
	scanf("%s",&u);
	
	if(strcmp(s,u)==0){
		printf("%d %d\n",a-1,b);
	}else if (strcmp(t,u)==0){
		printf("%d %d\n",a,b-1);
	}
	

return 0;
}
