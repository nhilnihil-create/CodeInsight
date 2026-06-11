#include<stdio.h>

int main(){
	
	int h;
	int a;
	scanf("%d %d",&h,&a);
	int d;
	d = h % a;
	int c;
	c = h / a;

	
	if(d>=1){
		printf("%d",c+1);
	}
	if(d<1){
		printf("%d",c);
	}
	
	
	
	
	return 0;
}