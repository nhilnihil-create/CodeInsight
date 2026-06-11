#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	if(x==1 && y==2 || x==2 && y==1){
		printf("3");
	}
	if(x==2 && y==3 || x==3 && y==2){
		printf("1");
	}
	if(x==1 && y==3 || x==3 && y==1){
		printf("2");
	}
	return 0;
}