#include<stdio.h>

int main(){
	int h,a,d,c;
	scanf("%d %d",&h,&a);
	d = h % a;
	c=h/a;
	if(d>=1){
		printf("%d",c+1);
	}
	if(d<1){
		printf("%d",c);
	}
	
}