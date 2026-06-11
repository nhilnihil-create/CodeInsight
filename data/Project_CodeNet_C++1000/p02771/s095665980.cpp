#include <stdio.h>

int main (){

	int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);

	if(a==b && a!=c && b!=c){
		printf("Yes\n");
	}else if(b==c && b!=a && c!=a){
		printf("Yes\n");
	}else if(a==c && a!=b && c!=b){
		printf("Yes\n");
	}else
		printf("No\n");

return 0;
}
