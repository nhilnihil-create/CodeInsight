#include<stdio.h>

int main(){
	
	int a;
	int b;
	int c;
	scanf("%d %d %d",&a,&b,&c);
	
	
	
	
	if(a>9 || b>9 || c>9 || a<1 || b<1 || c<1){
		printf("eror!");
	}
	else if(a == b && b == c && a == c){
		printf("No");
	}
	else if(a == b || a == c || b == c){
		printf("Yes");
	}
	else if(a>b || b>c || c>a){
		printf("No");
	}
	
	
	
	return 0;
}