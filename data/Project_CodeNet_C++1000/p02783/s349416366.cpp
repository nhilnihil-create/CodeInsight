#include<stdio.h>
int main(){
	int X;
	int Y;
	scanf("%d %d",&X,&Y);
	int total = (X-1)/Y+1;
	printf("%d",total);
}