#include<stdio.h>
int main(){
	int a;
	int b;
	int c;
	
	scanf("%d %d %d", &a,&b,&c);
	if(a==b && a!=c && b!=c){
		printf("Yes");
	}
	else if (b==c && b!=a && c!=a){
		printf("Yes");
	}
	else if (a==c && a!=b && b!=c){
		printf("Yes");
	}
	else if (a==b && a==c && b==c){
		printf("No");
	}
	else if(a!=b && a!=c && b!=c){
		printf("No");
	}
	
	return 0;
}