#include<stdio.h>
int main (){
	int a,b,c,d;
	
	scanf("%d %d %d",&a,&b,&c,&d);
	
	d=a+b+c;
	
	if(d<=21){
		printf("win");
	}
	
	else{
		printf("bust");
	}
	
	return 0;
	
}