#include<stdio.h>
int main(){
	
	int a;
	int b;
	
	scanf("%d %d",&a,&b);
	getchar();
	
	if(a==2 && b==1||a==1 && b==2){
		printf("3");
	}
		else if(a==2 && b==3||a==3 && b==2){
		printf("1");
	}
			else if(a==3 && b==1||a==1 && b==3){
		printf("2");
	}
	return 0;
}