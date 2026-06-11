#include <stdio.h>

int main(){

	int x,y;	scanf("%d",&x);

	y=x%10;

	if(y==3) printf("bon");

	else if(y==0||y==1||y==6||y==8) printf("pon");

	else printf("hon");

	return 0;

}